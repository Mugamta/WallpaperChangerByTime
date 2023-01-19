#include "time_management.h"

#include <iostream>

// https://coding-factory.tistory.com/668, https://ehpub.co.kr/localtime_s-%ED%95%A8%EC%88%98/ 참고

struct tm ReturnCurrentTime(int *year, int *month, int *mday, int *wday, int *hour, int *minute, int *second) {
	time_t timer = time(NULL);
	struct tm t;
	localtime_s(&t, &timer);

	*year = t.tm_year + 1900;
	*month = t.tm_mon + 1;
	*mday = t.tm_mday;
	*wday = t.tm_wday;
	*hour = t.tm_hour;
	*minute = t.tm_min;
	*second = t.tm_sec;

	return t;
}

void PrintTime(struct tm t) {
	std::cout << "현재 년: " << t.tm_year + 1900 << '\n';
	std::cout << "현재 월: " << t.tm_mon + 1 << '\n';
	std::cout << "현재 일: " << t.tm_mday << '\n';
	std::cout << "현재 시: " << t.tm_hour << '\n';
	std::cout << "현재 분: " << t.tm_min << '\n';
	std::cout << "현재 초: " << t.tm_sec << '\n';
	std::cout << "현재 요일: " << t.tm_wday << '\n';
}
