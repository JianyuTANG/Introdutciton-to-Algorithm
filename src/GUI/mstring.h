#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "bf.h"
#include "kmp.h"
#include "bm.h"
#include "TimeByClock.h"
using namespace std;


class mstring
{
public:
	string pattern,data;
	brutalforce bf;
	boyermoore bm;
	knuthmorrispratt kmp;
    vector<int> ans;
    vector<double> timecost;

public:
	mstring();
	void init(string &p);
	void input(string &p,string &t);
	void test();
    void run();
};
