#pragma once
#include <ctime>
#include <iostream>
#include <windows.h> 

class TimeByClock
{
public:
	clock_t start_time,end_time;
	LARGE_INTEGER  large_interger;  
    double dff;  
    __int64  c1, c2;

public:
	TimeByClock();
	~TimeByClock();
	void getstart();
	void getend();
	void report();
	double getdur();
	void getstart_precise();
	void getend_precise();
	void report_precise();
    double getdurp();
};
