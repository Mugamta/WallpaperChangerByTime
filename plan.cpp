#include "plan.h"

#include <iostream>

Plan::Plan(std::string image_name) {
	SetDate(image_name);
	this->image_name = image_name;
}

void Plan::SetDate(std::string image_name)
{
	//image_path�� month-day-hour-minute-name�� ����
	int idx = 1;
	int tmp;

	for (int i = 0; i < 4; ++i) {
		if (image_name[idx] == '-') { //-�� ����Ű�� �ִٸ� ���ڸ� ����
			tmp = image_name[idx - 1] - 48;
			idx += 2;
		}
		else { //Ȥ�� ���ڸ� ����
			tmp = 10 * (image_name[idx - 1] - 48) + image_name[idx] - 48;
			idx += 3;
		}

		switch (i) {
		case 0:
			month = tmp;
			break;
		case 1:
			day = tmp;
			break;
		case 2:
			hour = tmp;
			break;
		case 3:
			minute = tmp;
			break;
		}
	}
}
void Plan::PrintImageName() {
	std::cout << image_name << '\n';
}

void Plan::PrintDate() {
	if (month == 0) {
		std::cout << "���� ����� ������, ";
	}
	else {
		std::cout << month << "���� �۵��ϸ�, ";
	}

	if (day == 0) {
		std::cout << "���� ����� ������, ";
	}
	else {
		std::cout << day << "�Ͽ� �۵��ϸ�, ";
	}

	std::cout << hour << "��, " << minute << "�п� �۵�\n";
}