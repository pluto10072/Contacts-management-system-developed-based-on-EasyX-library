#include"Cperson.h"

//���캯��
Cperson::Cperson(char a[20], char b[20], char c[20], char d[20])
{
	strcpy_s(this->name , a);
	strcpy_s(this->site, b);
	strcpy_s(this->phonenum, c);
	strcpy_s(this->postal, d);

}

//��������
Cperson::~Cperson()
{

}

char* Cperson::showmsg()
{
	char* p = NULL;
	//��������ַ�������  (�����,����ռ�Ҫ���ٵ���Լ430��Ԫ�ؼ����ϲ���������ʾ,������������)
	char a[500] = { 0 };
	char b[3] = { " " };

	//�����������
	strcpy_s(a, this->name);
	strcat_s(a, b);
	
	strcat_s(a, this->site);
	strcat_s(a, b);
	
	strcat_s(a, this->phonenum);
	strcat_s(a, b);

	strcat_s(a, this->postal);
	
	//ָ��ָ���µ�����
	p = a;

	return p;


}