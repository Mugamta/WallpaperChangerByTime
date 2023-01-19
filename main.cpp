#include "main_run.h"
#include "time_management.h"
#include <iostream>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char*, int nShowCmd) {
	//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char*, int nShowCmd){ // 프로젝트 속성 - 링커 - 서브시스템 윈도우로 변경
	while (true) {
		main_run();

		std::cout << "하루의 바탕화면 변경이 종료되어 다음날까지 Sleep\n";

		//하루의 바탕화면 종료가 완료되었다면
		int year, month, mday, wday, hour, minute, second;
		ReturnCurrentTime(&year, &month, &mday, &wday, &hour, &minute, &second);

		//다음 날까지 Sleep
		Sleep(1000 * (60 * (60 * (23 - hour) + (59 - minute)) - second));
	}
}