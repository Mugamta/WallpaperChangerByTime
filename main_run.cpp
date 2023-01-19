#include "main_run.h"
#include <iostream>
#include <algorithm>
#include <queue>

bool compare(Plan a, Plan b) { //��, ��, �ð�, �� ������ �������� ����
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
	
	//PathExtractor������ ���� ���α׷��� ����ǰ� �ִ� ��ο��� image ������ ã�� ��θ� �����մϴ�. �̶� image ������ ������ ���α׷��� �����մϴ�.
	std::string base_path = PathExtractor();

	//image ������ �̹��� ����� �ҷ��ɴϴ�.
	std::vector<std::string> image_list = FileListExtractor(base_path);

	//�̹����� ������ ���� Plan�� ��ü�� ����� �����մϴ�.
	std::vector<Plan> plans;
	for (auto i : image_list) {
		if (i.length() >= 11) { //0-0-0-0.jpg�� ���� ������ �ּ� ���� 11
			plans.push_back(Plan(i));
		}
	}
	
	//���� �ð��� ���ɴϴ�.
	int year, month, mday, wday, hour, minute, second; // ��, ��, ��, ����, �ð�, ��
	ReturnCurrentTime(&year, &month, &mday, &wday, &hour, &minute, &second);
	
	//����ȭ���� ������ ������ ���� �����մϴ�.
	sort(plans.begin(), plans.end(), compare);

	//�켱 ������ ���� ��ü�� ����ϴ�. ��, ������ �������� �Ǵܵ˴ϴ�.
	//1. �ް� ���� ��ġ	2. ���� ��ġ 3. ���� ��ġ 4. �ð��� ��ġ
	//2�� 10�� 3�� 15���� ���, 2�� 10��, 2�� x��, x�� 10��, x�� x�� 3�� 15�� ������ �켱�˴ϴ�.

	std::queue<Plan> q;
	
	for (auto i : plans) {
		if (month == i.ReturnMonth() && mday == i.ReturnMday()) { //���� �� ��� ��ġ
			q.push(i);
		}
	}

	if (q.empty()) {
		for (auto i : plans) {
			if (month == i.ReturnMonth() && mday == 0) { //�� ��ġ
				q.push(i);
			}
		}
	}

	if (q.empty()) {
		for (auto i : plans) {
			if (month == 0 && mday == i.ReturnMday()) { //�� ��ġ
				q.push(i);
			}
		}
	}
	if (q.empty()) {
		for (auto i : plans) {
			if (i.ReturnMonth() == 0 && i.ReturnMday() == 0) { //���� ���� 0�� �׻� ����Ǵ� ����ȭ��
				q.push(i);
			}
		}
	}
	
	//���� �ð��� �������� ���� ����ȭ�� ������ ��ٸ��ϴ�.
	while (!q.empty()) {
		Plan first = q.front();

		if (first.ReturnHour() < hour || (first.ReturnHour() == hour && first.ReturnMinute() <= minute)) { //�̹� ���� �ð��̰ų� ���� �ð�
			q.pop();
			std::string str = base_path;
			str += first.ReturnName();

			std::wstring wstr;
			wstr.assign(str.begin(), str.end());

			LPCTSTR lpcString = wstr.c_str();

			SetDesktopWallPaper(lpcString, 0);
			std::cout << str << "���� ����\n";
		}
		else {
			ReturnCurrentTime(&year, &month, &mday, &wday, &hour, &minute, &second);
			std::cout << hour << ' ' << first.ReturnHour() << ' ' << minute << ' ' << first.ReturnMinute() << '\n';
			int tmp = 1000 * (60 * (60 * (first.ReturnHour() - hour) + first.ReturnMinute() - minute) - second);
			std::cout << "������� " << tmp/1000 << "�� ����\n";
			Sleep(tmp);
		}
	}


}