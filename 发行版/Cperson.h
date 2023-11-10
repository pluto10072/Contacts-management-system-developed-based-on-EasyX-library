#pragma once
#ifndef _CPERSON_H
#define _CPERSON_H
//图形库头文件
#include<graphics.h>
#include<cstring>

using namespace std;

class Cperson
{
public:
	char name[20];
	
	char site[20];

	char phonenum[20];

	char postal[20];

	Cperson(char a[20], char b[20], char c[20], char d[20]);

	~Cperson();

	char* showmsg();
};

#endif
