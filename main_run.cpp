#include "main_run.h"
#include <iostream>
#include <algorithm>
#include <queue>

bool compare(Plan a, Plan b) { //월, 일, 시간, 분 순으로 오름차순 정렬
	if (a.ReturnMonth() == b.ReturnMonth()) {
		if (a.ReturnMday() == b.ReturnMday()) {
			if (a.ReturnHour() == b.ReturnHour()) {
				a.ReturnMinute() < b.ReturnMinute();
			}
			a.ReturnHour() < b.ReturnHour();
		}
		a.ReturnMday() < b.ReturnMday();
	}
	return a.ReturnMonth() < b.ReturnMonth();
}

void main_run () {
	
	//PathExtractor에서는 현재 프로그램이 실행되고 있는 경로에서 image 폴더를 찾아 경로를 저장합니다. 이때 image 폴더가 없으면 프로그램을 종료합니다.
	std::string base_path = PathExtractor();

	//image 폴더의 이미지 목록을 불러옵니다.
	std::vector<std::string> image_list = FileListExtractor(base_path);

	//이미지의 정보를 각각 Plan의 객체로 만들어 저장합니다.
	std::vector<Plan> plans;
	for (auto i : image_list) {
		if (i.length() >= 11) { //0-0-0-0.jpg와 같은 형식은 최소 길이 11
			plans.push_back(Plan(i));
		}
	}
	
	//현재 시간을 얻어옵니다.
	int year, month, mday, wday, hour, minute, second; // 년, 월, 일, 요일, 시간, 분
	ReturnCurrentTime(&year, &month, &mday, &wday, &hour, &minute, &second);
	
	//바탕화면을 변경할 순서를 위해 정렬합니다.
	sort(plans.begin(), plans.end(), compare);

	//우선 순위에 따라 객체를 담습니다. 단, 오늘을 기준으로 판단됩니다.
	//1. 달과 일이 일치	2. 월이 일치 3. 일이 일치 4. 시각이 일치
	//2월 10일 3시 15분인 경우, 2월 10일, 2월 x일, x월 10일, x월 x일 3시 15분 순으로 우선됩니다.

	std::queue<Plan> q;
	
	for (auto i : plans) {
		if (month == i.ReturnMonth() && mday == i.ReturnMday()) { //월과 일 모두 일치
			q.push(i);
		}
	}

	if (q.empty()) {
		for (auto i : plans) {
			if (month == i.ReturnMonth() && mday == 0) { //월 일치
				q.push(i);
			}
		}
	}

	if (q.empty()) {
		for (auto i : plans) {
			if (month == 0 && mday == i.ReturnMday()) { //일 일치
				q.push(i);
			}
		}
	}
	if (q.empty()) {
		for (auto i : plans) {
			if (i.ReturnMonth() == 0 && i.ReturnMday() == 0) { //월과 일이 0인 항상 실행되는 바탕화면
				q.push(i);
			}
		}
	}
	
	//현재 시간을 기준으로 다음 바탕화면 변경을 기다립니다.
	while (!q.empty()) {
		Plan first = q.front();

		if (first.ReturnHour() < hour || (first.ReturnHour() == hour && first.ReturnMinute() <= minute)) { //이미 지난 시간이거나 현재 시간
			q.pop();
			std::string str = base_path;
			str += first.ReturnName();

			std::wstring wstr;
			wstr.assign(str.begin(), str.end());

			LPCTSTR lpcString = wstr.c_str();

			SetDesktopWallPaper(lpcString, 0);
			std::cout << str << "으로 변경\n";
		}
		else {
			ReturnCurrentTime(&year, &month, &mday, &wday, &hour, &minute, &second);
			std::cout << hour << ' ' << first.ReturnHour() << ' ' << minute << ' ' << first.ReturnMinute() << '\n';
			int tmp = 1000 * (60 * (60 * (first.ReturnHour() - hour) + first.ReturnMinute() - minute) - second);
			std::cout << "변경까지 " << tmp/1000 << "초 남음\n";
			Sleep(tmp);
		}
	}


}