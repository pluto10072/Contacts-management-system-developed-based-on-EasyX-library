
#include"manager.h"

int main()
{
	//����ʵ�����������
	manager wm;

	wm.init();

	wm.desk();

	HWND hnd = GetHWnd();

	SetWindowText(hnd, "ͨѶ¼����ϵͳ");

	int ok = MessageBox(hnd, "�ѽ�����Ա��ʼ��", "��ʾ", MB_OKCANCEL);

	while (1)
	{
		//��ȡ���������
		int mouse = Lmouse();
		switch (mouse)
		{
		//��Ա���
		case 1:
		{
			setbkcolor(WHITE);
			cleardevice();
			wm.addnew();
			break;
		}
		//��Ա��ѯ
		case 2:
		{
			setbkcolor(BLACK);
			cleardevice();
			wm.findone();
			break;
		}
		//��Ա�޸�
		case 3:
		{
			setbkcolor(BLACK);
			cleardevice();
			wm.rewrite();
			break;
		}
		//���ݱ���
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
