#include"mouse.h"
#include<graphics.h>
int Lmouse()
{
	//定义鼠标消息变量
	ExMessage msg;
	//获取鼠标消息
	while (peekmessage(&msg))
	{
		if (msg.message == WM_LBUTTONDOWN && msg.x >= 225 && msg.x <= 375 && msg.y >= 50 && msg.y <= 100)
		{
			return 1;
		}
		else if (msg.message == WM_LBUTTONDOWN && msg.x >= 225 && msg.x <= 375 && msg.y >= 150 && msg.y <= 200)
		{
			return 2;
		}
		else if (msg.message == WM_LBUTTONDOWN && msg.x >= 225 && msg.x <= 375 && msg.y >= 250 && msg.y <= 300)
		{
			return 3;
		}
		else if (msg.message == WM_LBUTTONDOWN && msg.x >= 225 && msg.x <= 375 && msg.y >= 350 && msg.y <= 400)
		{
			return 4;

		}
		else if (msg.message == WM_LBUTTONDOWN && msg.x >= 425 && msg.x <= 575 && msg.y >= 400 && msg.y <= 450)
		{
			return 5;
		}
	}

	return 0;

}