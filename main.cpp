#include "main_run.h"
#include "time_management.h"
#include <iostream>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char*, int nShowCmd) {
	//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char*, int nShowCmd){ // ������Ʈ �Ӽ� - ��Ŀ - ����ý��� ������� ����
	while (true) {
		main_run();

		std::cout << "�Ϸ��� ����ȭ�� ������ ����Ǿ� ���������� Sleep\n";

		//�Ϸ��� ����ȭ�� ���ᰡ �Ϸ�Ǿ��ٸ�
		int year, month, mday, wday, hour, minute, second;
		ReturnCurrentTime(&year, &month, &mday, &wday, &hour, &minute, &second);

		//���� ������ Sleep
		Sleep(1000 * (60 * (60 * (23 - hour) + (59 - minute)) - second));
	}
}