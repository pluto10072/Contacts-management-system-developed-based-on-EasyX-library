#include"manager.h"

//��������
manager::~manager()
{

}

//��ȡ�ļ�����Ա�ĸ���
int manager::getnum()
{
	int tempnumber = 0;

	ifstream file1;
	file1.open("people.txt", ios::in);
	if (!file1)
	{
		exit(2);
	}

	char a[20] = { 0 };
	char b[20] = { 0 };
	char c[20] = { 0 };
	char d[20] = { 0 };

	while (file1 >> a && file1 >> b && file1 >> c && file1 >> d)
	{
		++tempnumber;
	}

	file1.close();

	return tempnumber;
}

//�ļ����ݵ��뵽��Ա������
void manager::init()
{

	//���ݻ�ȡ����Ա�����ڶ��������¿ռ�
	this->number = this->getnum();
	this->personarray = new Cperson * [this->number + 1];


	int tempnumber = 0;

	ifstream file1;
	file1.open("people.txt", ios::in);
	if (!file1)
	{
		exit(2);
	}

	char a[20] = { 0 };
	char b[20] = { 0 };
	char c[20] = { 0 };
	char d[20] = { 0 };

	while (!file1.eof())
	{
		file1 >> a;
		file1 >> b;
		file1 >> c;
		file1 >> d;
		//��ʼ��
		Cperson* newone = NULL;
		
		newone = new Cperson(a, b, c, d);

		//ע������Խ��
		this->personarray[tempnumber] = newone;

		++tempnumber;

	}

	//�ر��ļ�
	file1.close();

}

void manager::desk()
{
	//��ʼ������
	initgraph(640, 480, 0);
	//���ñ�����ɫ
	setbkcolor(WHITE);
	//ˢ�´���
	cleardevice();
	//����ͼƬ����
	IMAGE pic1;
	loadimage(&pic1, "123.jpg",640,480);
	putimage(0, 0, &pic1);

	//���������ɫ
	setfillcolor(BLACK);
	//���ư�ť(������)
	solidrectangle(225, 100, 375, 50);
	solidrectangle(225, 200, 375, 150);
	solidrectangle(225, 300, 375, 250);
	solidrectangle(225, 400, 375, 350);
	//����������ɫ
	settextcolor(WHITE);
	//�������屳��͸��
	setbkmode(1);
	//�����ַ���
	outtextxy(265, 68, _T("��Ա���"));
	outtextxy(265, 168, _T("��Ա��ѯ"));
	outtextxy(265, 268, _T("��Ա�޸�"));
	outtextxy(265, 368, _T("���ݱ���"));
}

//�������Ա
void manager::addnew()
{
	//ˢ�´���
	cleardevice();
	//����ͼƬ����
	IMAGE pic1;
	loadimage(&pic1, "123.jpg", 640, 480);
	putimage(0, 0, &pic1);
	//�����¿ռ�
	Cperson** newspace = new Cperson * [this->number + 1];
	//�̳�ԭ������
	if (this->personarray != NULL)
	{
		for (int i = 0; i < this->number; ++i)
		{
			newspace[i] = this->personarray[i];
		}
	}
	char a[20];
	InputBox(a, 20, "������Ҫ��ӵ�����");
	char b[20];
	InputBox(b, 20, "�������ַ");
	char c[20];
	InputBox(c, 20, "������绰����");
	char d[20];
	InputBox(d, 20, "��������������");

	//��ʼ���³�Աָ��
	Cperson* newone = NULL;

	//��ʼ���³�Ա
	newone = new Cperson(a, b, c, d);

	//�����³�Ա
	newspace[this->number] = newone;

	//�ͷ�ԭ�пռ�
	delete[] this->personarray;

	//ָ���¿ռ�
	this->personarray = newspace;

	//��������
	++this->number;

	//���ư�ť(������)
	solidrectangle(425, 450, 575, 400);
	//����������ɫ
	settextcolor(WHITE);
	//�������屳��͸��
	setbkmode(1);
	//�����ַ���
	outtextxy(465, 418, _T("���ز˵�"));
	//����������ɫ
	settextcolor(BLACK);
	
	HWND hnd = GetHWnd();

	int ok = MessageBox(hnd, "��ӳɹ�", "��ʾ", MB_OKCANCEL);

	while (1)
	{
		int mouse = Lmouse();
		if (mouse == 5)
		{
			this->desk();
			break;
		}
	}

}


//��ѯ��Ա
void manager::findone()
{
	//ˢ�´���
	cleardevice();
	//����ͼƬ����
	IMAGE pic1;
	loadimage(&pic1, "123.jpg", 640, 480);
	putimage(0, 0, &pic1);
	//���ư�ť(������)
	solidrectangle(225, 100, 375, 50);
	solidrectangle(225, 200, 375, 150);
	solidrectangle(425, 450, 575, 400);
	//����������ɫ
	settextcolor(WHITE);
	//�������屳��͸��
	setbkmode(1);
	//�����ַ���
	outtextxy(265, 68, _T("ȫ����ѯ"));
	outtextxy(265, 168, _T("������ѯ"));
	outtextxy(465, 418, _T("���ز˵�"));

	int a = 1;
	while (a)
	{
		int mouse = Lmouse();
		switch (mouse)
		{
		//ȫ����ѯ
		case 1:
			{
				//����ͼƬ����
				IMAGE pic2;
				loadimage(&pic2, "1.jpg", 640, 480);
				putimage(0, 0, &pic2);
				//���ư�ť(������)
				solidrectangle(425, 450, 575, 400);
				//����������ɫ
				settextcolor(WHITE);
				//�������屳��͸��
				setbkmode(1);
				//�����ַ���
				outtextxy(465, 418, _T("���ز˵�"));
				//����������ɫ
				settextcolor(BLACK);
				
				//���Ʊ�ͷ����
				outtextxy(50, 20, _T("����"));
				outtextxy(110, 20, _T("��ַ"));
				outtextxy(190, 20, _T("�绰����"));
				outtextxy(260, 20, _T("��������"));

				for (int i = 0; i < this->number; ++i)
				{
					char* p;
					p = this->personarray[i]->showmsg();

					outtextxy(50, (i + 2) * 25 , p);
				}

				break;
			}
		case 2:
			{
				//ˢ�´���
				cleardevice();
				//����ͼƬ����
				IMAGE pic1;
				loadimage(&pic1, "123.jpg", 640, 480);
				putimage(0, 0, &pic1);

				//�����û�����
				char s[80];
				InputBox(s, 80, "������Ҫ��ѯ������");

				//����ͼƬ����
				IMAGE pic2;
				loadimage(&pic2, "1.jpg", 640, 480);
				putimage(0, 0, &pic2);

				//���ư�ť(������)
				solidrectangle(425, 450, 575, 400);
				//����������ɫ
				settextcolor(WHITE);
				//�������屳��͸��
				setbkmode(1);
				//�����ַ���
				outtextxy(465, 418, _T("���ز˵�"));
				//����������ɫ
				settextcolor(BLACK);

				int n = 0;
				for (int i = 0; i < this->number; ++i)
				{
					if (strcmp(s, this->personarray[i]->name) == 0)
					{
						char* p;
						p = this->personarray[i]->showmsg();

						//���Ʊ�ͷ����
						outtextxy(50, 20, _T("����"));
						outtextxy(110, 20, _T("��ַ"));
						outtextxy(190, 20, _T("�绰����"));
						outtextxy(260, 20, _T("��������"));

						outtextxy(50, 50, p);
						++n;
						break;
					}
				}
				if (n == 0)
				{
					HWND hnd = GetHWnd();

					int ok = MessageBox(hnd, "δ��ѯ������", "��ʾ", MB_OKCANCEL);
				}

				break;
			}
		case 5:
		{
			this->desk();
			--a;
			break;
		}
		}
	}
	
}

//�������ݵ��ļ�
void manager::save()
{
	//ˢ�´���
	cleardevice();
	//����ͼƬ����
	IMAGE pic1;
	loadimage(&pic1, "123.jpg", 640, 480);
	putimage(0, 0, &pic1);


	ofstream file2;
	file2.open("people.txt", ios::out);

	if (!file2)
	{
		exit(2);
	}

	for (int i = 0; i < this->number; ++i)
	{
		file2 << this->personarray[i]->name << ' '
			  << this->personarray[i]->site << ' '
			  << this->personarray[i]->phonenum << ' '
			  << this->personarray[i]->postal << endl ;
	}


	//���ư�ť(������)
	solidrectangle(425, 450, 575, 400);
	//����������ɫ
	settextcolor(WHITE);
	//�������屳��͸��
	setbkmode(1);
	//�����ַ���
	outtextxy(465, 418, _T("���ز˵�"));

	HWND hnd = GetHWnd();

	int ok = MessageBox(hnd, "����ɹ�", "��ʾ", MB_OKCANCEL);

	while (1)
	{
		int mouse = Lmouse();
		if (mouse == 5)
		{
			this->desk();
			break;
		}
	}

	file2.close();
}

//�޸���Ա��Ϣ
void manager::rewrite()
{
	//ˢ�´���
	cleardevice();
	//����ͼƬ����
	IMAGE pic1;
	loadimage(&pic1, "123.jpg", 640, 480);
	putimage(0, 0, &pic1);
	//���ư�ť(������)
	solidrectangle(225, 100, 375, 50);
	solidrectangle(225, 200, 375, 150);
	solidrectangle(425, 450, 575, 400);
	//����������ɫ
	settextcolor(WHITE);
	//�������屳��͸��
	setbkmode(1);
	//�����ַ���
	outtextxy(265, 68, _T("ɾ����Ա"));
	outtextxy(265, 168, _T("�޸���Ϣ"));
	outtextxy(465, 418, _T("���ز˵�"));

	int a = 1;
	while (a)
	{
			int mouse = Lmouse();
			switch (mouse)
			{
			//ɾ����Ա
			case 1:
			{
				//ˢ�´���
				cleardevice();
				//����ͼƬ����
				IMAGE pic1;
				loadimage(&pic1, "123.jpg", 640, 480);
				putimage(0, 0, &pic1);
				//����������ɫ
				settextcolor(BLACK);
				//�������屳��͸��
				setbkmode(1);
				//�����û�����
				char s[80];
				InputBox(s, 80, "������Ҫɾ��������");

				//Ѱ����ͬ����
				int temp = -5;
				for (int i = 0; i < this->number; ++i)
				{
					if (strcmp(s, this->personarray[i]->name) == 0)
					{
						temp = i;
						break;
					}
				}

				//�ҵ���ͬ����
				if (temp >= 0)
				{
					Cperson** newspace = new Cperson * [this->number - 1];
					int i = 0;
					int j = 0;
					while (i < this->number)
					{
						if (i != temp)
						{
							newspace[j] = this->personarray[i];
							++j;
						}
						++i;
					}
					//�ͷ�ԭ�пռ�
					delete[] this->personarray;

					//ָ���¿ռ�
					this->personarray = newspace;

					//��������
					--this->number;

					HWND hnd = GetHWnd();

					int ok = MessageBox(hnd, "ɾ���ɹ�", "��ʾ", MB_OKCANCEL);
				}
				//δ�ҵ�
				else
				{
					HWND hnd = GetHWnd();

					int ok = MessageBox(hnd, "���˲�����", "��ʾ", MB_OKCANCEL);
				}

				solidrectangle(425, 450, 575, 400);
				//����������ɫ
				settextcolor(WHITE);
				//�������屳��͸��
				setbkmode(1);
				//�����ַ���
				outtextxy(465, 418, _T("���ز˵�"));

				break;
			}
			//�޸���Ϣ
			case 2:
			{
				//ˢ�´���
				cleardevice();
				//����ͼƬ����
				IMAGE pic1;
				loadimage(&pic1, "123.jpg", 640, 480);
				putimage(0, 0, &pic1);
				//����������ɫ
				settextcolor(BLACK);
				//�������屳��͸��
				setbkmode(1);
				//�����û�����
				char s[80];
				InputBox(s, 80, "��������Ҫ�޸ĵ�����");
				
				//Ѱ����ͬ����
				int temp = -5;
				for (int i = 0; i < this->number; ++i)
				{
					if (strcmp(s, this->personarray[i]->name) == 0)
					{
						temp = i;
						break;
					}
				}

				if (temp >= 0)
				{
					char a[20];
					InputBox(a, 20, "�������µĵ�ַ");
					char b[20];
					InputBox(b, 20, "�������µĵ绰����");
					char c[20];
					InputBox(c, 20, "�������µ���������");

					strcpy_s(this->personarray[temp]->site, a);
					strcpy_s(this->personarray[temp]->phonenum, b);
					strcpy_s(this->personarray[temp]->postal, c);

					HWND hnd = GetHWnd();

					int ok = MessageBox(hnd, "�޸ĳɹ�", "��ʾ", MB_OKCANCEL);

				}
				else
				{
					HWND hnd = GetHWnd();

					int ok = MessageBox(hnd, "���˲�����", "��ʾ", MB_OKCANCEL);
				}

				solidrectangle(425, 450, 575, 400);
				//����������ɫ
				settextcolor(WHITE);
				//�������屳��͸��
				setbkmode(1);
				//�����ַ���
				outtextxy(465, 418, _T("���ز˵�"));

				break;
			}
			case 5:
			{
				this->desk();
				--a;
				break;
			}

			}
	}
	
}