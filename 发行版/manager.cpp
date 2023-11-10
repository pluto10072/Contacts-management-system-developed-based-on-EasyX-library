#include"manager.h"

//析构函数
manager::~manager()
{

}

//获取文件中人员的个数
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

//文件内容导入到人员数组中
void manager::init()
{

	//根据获取的人员个数在堆区开辟新空间
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
		//初始化
		Cperson* newone = NULL;
		
		newone = new Cperson(a, b, c, d);

		//注意数组越界
		this->personarray[tempnumber] = newone;

		++tempnumber;

	}

	//关闭文件
	file1.close();

}

void manager::desk()
{
	//初始化窗口
	initgraph(640, 480, 0);
	//设置背景颜色
	setbkcolor(WHITE);
	//刷新窗口
	cleardevice();
	//定义图片变量
	IMAGE pic1;
	loadimage(&pic1, "123.jpg",640,480);
	putimage(0, 0, &pic1);

	//设置填充颜色
	setfillcolor(BLACK);
	//绘制按钮(填充矩形)
	solidrectangle(225, 100, 375, 50);
	solidrectangle(225, 200, 375, 150);
	solidrectangle(225, 300, 375, 250);
	solidrectangle(225, 400, 375, 350);
	//设置字体颜色
	settextcolor(WHITE);
	//设置字体背景透明
	setbkmode(1);
	//绘制字符串
	outtextxy(265, 68, _T("人员添加"));
	outtextxy(265, 168, _T("人员查询"));
	outtextxy(265, 268, _T("人员修改"));
	outtextxy(265, 368, _T("数据保存"));
}

//添加新人员
void manager::addnew()
{
	//刷新窗口
	cleardevice();
	//定义图片变量
	IMAGE pic1;
	loadimage(&pic1, "123.jpg", 640, 480);
	putimage(0, 0, &pic1);
	//开辟新空间
	Cperson** newspace = new Cperson * [this->number + 1];
	//继承原有数据
	if (this->personarray != NULL)
	{
		for (int i = 0; i < this->number; ++i)
		{
			newspace[i] = this->personarray[i];
		}
	}
	char a[20];
	InputBox(a, 20, "请输入要添加的人名");
	char b[20];
	InputBox(b, 20, "请输入地址");
	char c[20];
	InputBox(c, 20, "请输入电话号码");
	char d[20];
	InputBox(d, 20, "请输入邮政编码");

	//初始化新成员指针
	Cperson* newone = NULL;

	//初始化新成员
	newone = new Cperson(a, b, c, d);

	//加入新成员
	newspace[this->number] = newone;

	//释放原有空间
	delete[] this->personarray;

	//指向新空间
	this->personarray = newspace;

	//更新人数
	++this->number;

	//绘制按钮(填充矩形)
	solidrectangle(425, 450, 575, 400);
	//设置字体颜色
	settextcolor(WHITE);
	//设置字体背景透明
	setbkmode(1);
	//绘制字符串
	outtextxy(465, 418, _T("返回菜单"));
	//设置字体颜色
	settextcolor(BLACK);
	
	HWND hnd = GetHWnd();

	int ok = MessageBox(hnd, "添加成功", "提示", MB_OKCANCEL);

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


//查询人员
void manager::findone()
{
	//刷新窗口
	cleardevice();
	//定义图片变量
	IMAGE pic1;
	loadimage(&pic1, "123.jpg", 640, 480);
	putimage(0, 0, &pic1);
	//绘制按钮(填充矩形)
	solidrectangle(225, 100, 375, 50);
	solidrectangle(225, 200, 375, 150);
	solidrectangle(425, 450, 575, 400);
	//设置字体颜色
	settextcolor(WHITE);
	//设置字体背景透明
	setbkmode(1);
	//绘制字符串
	outtextxy(265, 68, _T("全部查询"));
	outtextxy(265, 168, _T("条件查询"));
	outtextxy(465, 418, _T("返回菜单"));

	int a = 1;
	while (a)
	{
		int mouse = Lmouse();
		switch (mouse)
		{
		//全部查询
		case 1:
			{
				//定义图片变量
				IMAGE pic2;
				loadimage(&pic2, "1.jpg", 640, 480);
				putimage(0, 0, &pic2);
				//绘制按钮(填充矩形)
				solidrectangle(425, 450, 575, 400);
				//设置字体颜色
				settextcolor(WHITE);
				//设置字体背景透明
				setbkmode(1);
				//绘制字符串
				outtextxy(465, 418, _T("返回菜单"));
				//设置字体颜色
				settextcolor(BLACK);
				
				//绘制表头数据
				outtextxy(50, 20, _T("姓名"));
				outtextxy(110, 20, _T("地址"));
				outtextxy(190, 20, _T("电话号码"));
				outtextxy(260, 20, _T("邮政编码"));

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
				//刷新窗口
				cleardevice();
				//定义图片变量
				IMAGE pic1;
				loadimage(&pic1, "123.jpg", 640, 480);
				putimage(0, 0, &pic1);

				//接收用户输入
				char s[80];
				InputBox(s, 80, "请输入要查询的人名");

				//定义图片变量
				IMAGE pic2;
				loadimage(&pic2, "1.jpg", 640, 480);
				putimage(0, 0, &pic2);

				//绘制按钮(填充矩形)
				solidrectangle(425, 450, 575, 400);
				//设置字体颜色
				settextcolor(WHITE);
				//设置字体背景透明
				setbkmode(1);
				//绘制字符串
				outtextxy(465, 418, _T("返回菜单"));
				//设置字体颜色
				settextcolor(BLACK);

				int n = 0;
				for (int i = 0; i < this->number; ++i)
				{
					if (strcmp(s, this->personarray[i]->name) == 0)
					{
						char* p;
						p = this->personarray[i]->showmsg();

						//绘制表头数据
						outtextxy(50, 20, _T("姓名"));
						outtextxy(110, 20, _T("地址"));
						outtextxy(190, 20, _T("电话号码"));
						outtextxy(260, 20, _T("邮政编码"));

						outtextxy(50, 50, p);
						++n;
						break;
					}
				}
				if (n == 0)
				{
					HWND hnd = GetHWnd();

					int ok = MessageBox(hnd, "未查询到此人", "提示", MB_OKCANCEL);
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

//保存数据到文件
void manager::save()
{
	//刷新窗口
	cleardevice();
	//定义图片变量
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


	//绘制按钮(填充矩形)
	solidrectangle(425, 450, 575, 400);
	//设置字体颜色
	settextcolor(WHITE);
	//设置字体背景透明
	setbkmode(1);
	//绘制字符串
	outtextxy(465, 418, _T("返回菜单"));

	HWND hnd = GetHWnd();

	int ok = MessageBox(hnd, "保存成功", "提示", MB_OKCANCEL);

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

//修改人员信息
void manager::rewrite()
{
	//刷新窗口
	cleardevice();
	//定义图片变量
	IMAGE pic1;
	loadimage(&pic1, "123.jpg", 640, 480);
	putimage(0, 0, &pic1);
	//绘制按钮(填充矩形)
	solidrectangle(225, 100, 375, 50);
	solidrectangle(225, 200, 375, 150);
	solidrectangle(425, 450, 575, 400);
	//设置字体颜色
	settextcolor(WHITE);
	//设置字体背景透明
	setbkmode(1);
	//绘制字符串
	outtextxy(265, 68, _T("删除人员"));
	outtextxy(265, 168, _T("修改信息"));
	outtextxy(465, 418, _T("返回菜单"));

	int a = 1;
	while (a)
	{
			int mouse = Lmouse();
			switch (mouse)
			{
			//删除人员
			case 1:
			{
				//刷新窗口
				cleardevice();
				//定义图片变量
				IMAGE pic1;
				loadimage(&pic1, "123.jpg", 640, 480);
				putimage(0, 0, &pic1);
				//设置字体颜色
				settextcolor(BLACK);
				//设置字体背景透明
				setbkmode(1);
				//接收用户输入
				char s[80];
				InputBox(s, 80, "请输入要删除的人名");

				//寻找相同人名
				int temp = -5;
				for (int i = 0; i < this->number; ++i)
				{
					if (strcmp(s, this->personarray[i]->name) == 0)
					{
						temp = i;
						break;
					}
				}

				//找到相同人名
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
					//释放原有空间
					delete[] this->personarray;

					//指向新空间
					this->personarray = newspace;

					//更新人数
					--this->number;

					HWND hnd = GetHWnd();

					int ok = MessageBox(hnd, "删除成功", "提示", MB_OKCANCEL);
				}
				//未找到
				else
				{
					HWND hnd = GetHWnd();

					int ok = MessageBox(hnd, "此人不存在", "提示", MB_OKCANCEL);
				}

				solidrectangle(425, 450, 575, 400);
				//设置字体颜色
				settextcolor(WHITE);
				//设置字体背景透明
				setbkmode(1);
				//绘制字符串
				outtextxy(465, 418, _T("返回菜单"));

				break;
			}
			//修改信息
			case 2:
			{
				//刷新窗口
				cleardevice();
				//定义图片变量
				IMAGE pic1;
				loadimage(&pic1, "123.jpg", 640, 480);
				putimage(0, 0, &pic1);
				//设置字体颜色
				settextcolor(BLACK);
				//设置字体背景透明
				setbkmode(1);
				//接收用户输入
				char s[80];
				InputBox(s, 80, "请输入需要修改的人名");
				
				//寻找相同人名
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
					InputBox(a, 20, "请输入新的地址");
					char b[20];
					InputBox(b, 20, "请输入新的电话号码");
					char c[20];
					InputBox(c, 20, "请输入新的邮政编码");

					strcpy_s(this->personarray[temp]->site, a);
					strcpy_s(this->personarray[temp]->phonenum, b);
					strcpy_s(this->personarray[temp]->postal, c);

					HWND hnd = GetHWnd();

					int ok = MessageBox(hnd, "修改成功", "提示", MB_OKCANCEL);

				}
				else
				{
					HWND hnd = GetHWnd();

					int ok = MessageBox(hnd, "此人不存在", "提示", MB_OKCANCEL);
				}

				solidrectangle(425, 450, 575, 400);
				//设置字体颜色
				settextcolor(WHITE);
				//设置字体背景透明
				setbkmode(1);
				//绘制字符串
				outtextxy(465, 418, _T("返回菜单"));

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