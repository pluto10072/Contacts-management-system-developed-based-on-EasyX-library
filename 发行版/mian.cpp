
#include"manager.h"

int main()
{
	//创建实例化管理对象
	manager wm;

	wm.init();

	wm.desk();

	HWND hnd = GetHWnd();

	SetWindowText(hnd, "通讯录管理系统");

	int ok = MessageBox(hnd, "已进行人员初始化", "提示", MB_OKCANCEL);

	while (1)
	{
		//读取鼠标点击坐标
		int mouse = Lmouse();
		switch (mouse)
		{
		//人员添加
		case 1:
		{
			setbkcolor(WHITE);
			cleardevice();
			wm.addnew();
			break;
		}
		//人员查询
		case 2:
		{
			setbkcolor(BLACK);
			cleardevice();
			wm.findone();
			break;
		}
		//人员修改
		case 3:
		{
			setbkcolor(BLACK);
			cleardevice();
			wm.rewrite();
			break;
		}
		//数据保存
		case 4:
		{
			setbkcolor(BLACK);
			cleardevice();
			wm.save();
			break;
		}
		}

	}
	system("pause");
	return 0;
}
