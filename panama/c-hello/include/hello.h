#pragma once

// ref: https://atomheartother.github.io/c++/2018/07/12/CPPDynLib.html

// Define EXPORTED for any platform
#if defined _WIN32 || defined __CYGWIN__
#ifdef WIN_EXPORT
// Exporting...
#ifdef __GNUC__
#define EXPORTED __attribute__ ((dllexport))
#else
#define EXPORTED __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
#endif
#else
#ifdef __GNUC__
#define EXPORTED __attribute__ ((dllimport))
#else
#define EXPORTED __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
#endif
#endif
#define NOT_EXPORTED
#else
#if __GNUC__ >= 4
#define EXPORTED __attribute__ ((visibility ("default")))
#define NOT_EXPORTED  __attribute__ ((visibility ("hidden")))
#else
#define EXPORTED
#define NOT_EXPORTED
#endif
#endif

typedef enum
  {
   NONE,
   A,
   B
  } TestEnum;

typedef union TestUnion
{
  TestEnum type;
  int padding[2];
} TestUnion;

typedef struct AStruct
{
  TestEnum type;
  int a1;
} AStruct;

typedef struct BStruct
{
  TestEnum type;
  int b1;
  int b2;
} BStruct;

int SIZE = 12;

EXPORTED int hello(int, int);
EXPORTED TestUnion* test_malloc(int);
EXPORTED void test_free(TestUnion*);
EXPORTED char* inc_chararr(char*);
