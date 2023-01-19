#pragma once

#include <string>

class Plan
{
private:
	int month = 1, day = 1, hour = 0, minute = 0;
	std::string image_name = "";

public:
	Plan(std::string image_name);

	void SetDate(std::string image_name);
	void PrintDate();
	void PrintImageName();

	std::string ReturnName() { return image_name;}
	int ReturnMonth() { return month; }
	int ReturnMday() { return day; }
	int ReturnHour() { return hour; }
	int ReturnMinute() { return minute; }
};
