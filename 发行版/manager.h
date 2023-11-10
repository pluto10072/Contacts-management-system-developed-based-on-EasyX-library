#pragma once
#ifndef _MANAGER_H
#define _MANAGER_H
//图形库头文件
#include<graphics.h>
//系统头文件
#include<cstring>
#include<fstream>
//自定义头文件
#include"Cperson.h"
#include"mouse.h"

using namespace std;

class manager
{
public:
	int number;

	Cperson** personarray;

	~manager();

	//得到文件中人员个数
	int getnum();

	//文件装入
	void init();

	//初始化菜单
	void desk();

	//添加新人员
	void addnew();

	//查询人员
	void findone();

	//保存数据到文件
	void save();

	//修改人员信息
	void rewrite();

};


#endif
