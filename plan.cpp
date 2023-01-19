#include "plan.h"

#include <iostream>

Plan::Plan(std::string image_name) {
	SetDate(image_name);
	this->image_name = image_name;
}

void Plan::SetDate(std::string image_name)
{
	//image_path는 month-day-hour-minute-name로 구성
	int idx = 1;
	int tmp;

	for (int i = 0; i < 4; ++i) {
		if (image_name[idx] == '-') { //-를 가르키고 있다면 한자리 숫자
			tmp = image_name[idx - 1] - 48;
			idx += 2;
		}
		else { //혹은 두자리 숫자
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
		std::cout << "월은 상관이 없으며, ";
	}
	else {
		std::cout << month << "월에 작동하며, ";
	}

	if (day == 0) {
		std::cout << "일은 상관이 없으며, ";
	}
	else {
		std::cout << day << "일에 작동하며, ";
	}

	std::cout << hour << "시, " << minute << "분에 작동\n";
}