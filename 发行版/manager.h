#pragma once
#ifndef _MANAGER_H
#define _MANAGER_H
//ͼ�ο�ͷ�ļ�
#include<graphics.h>
//ϵͳͷ�ļ�
#include<cstring>
#include<fstream>
//�Զ���ͷ�ļ�
#include"Cperson.h"
#include"mouse.h"

using namespace std;

class manager
{
public:
	int number;

	Cperson** personarray;

	~manager();

	//�õ��ļ�����Ա����
	int getnum();

	//�ļ�װ��
	void init();

	//��ʼ���˵�
	void desk();

	//�������Ա
	void addnew();

	//��ѯ��Ա
	void findone();

	//�������ݵ��ļ�
	void save();

	//�޸���Ա��Ϣ
	void rewrite();

};


#endif
