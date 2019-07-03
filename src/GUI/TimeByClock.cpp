#include "TimeByClock.h"

TimeByClock::TimeByClock()
{
}

TimeByClock::~TimeByClock()
{
}

void TimeByClock::getstart()
{
	start_time=clock();
}

void TimeByClock::getend()
{
	end_time=clock();
}

void TimeByClock::report()
{
	clock_t dur=end_time-start_time;
	double r=(double)dur/(double)CLOCKS_PER_SEC;
	if(r>1)
		std::cout<<"��ʱ"<<r<<"��";
	else
		std::cout<<"��ʱ"<<dur<<"����";
	std::cout<<std::endl;
}

double TimeByClock::getdur()
{
	clock_t dur=end_time-start_time;
	return (double)dur;
}

void TimeByClock::getstart_precise()
{
	QueryPerformanceFrequency(&large_interger);  
    dff = large_interger.QuadPart;
	QueryPerformanceCounter(&large_interger);  
    c1 = large_interger.QuadPart;
}

void TimeByClock::getend_precise()
{
	QueryPerformanceCounter(&large_interger);  
    c2 = large_interger.QuadPart;
}

void TimeByClock::report_precise()
{
	std::cout<<"��ʱ"<<((c2-c1)*1000/dff)<<"ms\n";
}

double TimeByClock::getdurp()
{
    return ((c2-c1)*1000/dff);
}
