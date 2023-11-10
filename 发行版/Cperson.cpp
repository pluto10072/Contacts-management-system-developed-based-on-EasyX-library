#include"Cperson.h"

//构造函数
Cperson::Cperson(char a[20], char b[20], char c[20], char d[20])
{
	strcpy_s(this->name , a);
	strcpy_s(this->site, b);
	strcpy_s(this->phonenum, c);
	strcpy_s(this->postal, d);

}

//析构函数
Cperson::~Cperson()
{

}

char* Cperson::showmsg()
{
	char* p = NULL;
	//开辟输出字符串数组  (很奇怪,数组空间要开辟到大约430个元素及以上才能正常显示,否则会输出乱码)
	char a[500] = { 0 };
	char b[3] = { " " };

	//连接输出数据
	strcpy_s(a, this->name);
	strcat_s(a, b);
	
	strcat_s(a, this->site);
	strcat_s(a, b);
	
	strcat_s(a, this->phonenum);
	strcat_s(a, b);

	strcat_s(a, this->postal);
	
	//指针指向新的数组
	p = a;

	return p;


}