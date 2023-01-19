#pragma once

#include <ctime>

struct tm ReturnCurrentTime(int* year, int* month, int* mday, int* wday, int* hour, int* minute, int* second);

void PrintTime(struct tm);