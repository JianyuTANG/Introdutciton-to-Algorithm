#include "mstring.h"

mstring::mstring()
{
}

void mstring::init(string &p)
{
	bf.init(p);
	bm.init(p);
}

void mstring::input(string &p,string &t)
{
	pattern='0'+p;
	data=t;
    ans.clear();
    timecost.clear();
}

void mstring::test()
{
	TimeByClock timer;
	timer.getstart();
	bf.init(pattern);
	bf.cal(data,pattern);
	timer.getend();
	
	timer.getstart();
	kmp.init(pattern);
	kmp.cal(data,pattern);
	timer.getend();
	timer.getstart();
	bm.init(pattern);
	bm.cal(data,pattern);
	timer.getend();
}

void mstring::run()
{
    TimeByClock timer;
    //timer.getstart();
    timer.getstart_precise();
    bf.init(pattern);
    bf.cal(data,pattern);
    timer.getend_precise();
    timecost.push_back(timer.getdurp());
    timer.getstart_precise();
    kmp.init(pattern);
    kmp.cal(data,pattern);
    timer.getend_precise();
    timecost.push_back(timer.getdurp());
    timer.getstart_precise();
    bm.init(pattern);
    bm.cal(data,pattern);
    timer.getend_precise();
    timecost.push_back(timer.getdurp());

}
