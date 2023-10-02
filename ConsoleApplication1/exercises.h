#pragma once
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using std::cout;
using std::cin;

template <typename T>
static T input(std::string& text);
template <typename T>
static T input(const char* text);

template <typename T>
void clearArray(T* arr, int size);
template <typename T>
void showArray(T* arr, int size);
template <typename T>
T maxInArr(T* arr, int size);
template <typename T>
T minInArr(T* arr, int size);

inline const char* dayOfWeek(int num);

static void exercise1();
static void exercise2();
static void exercise3();
static void exercise4();
static void exercise5();
static void exercise6();
static void exercise7();
static void exercise8();
static void exercise9();

inline double congruential(int& x);
static void exercise10();
static void exercise11();
static void exercise12();