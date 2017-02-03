#include<stdio.h>
#include<stack>
using std::stack;
#define MAXSIZE 201
/*
���� �꽭�ivy22233qiu@live.com)
���� ���׼�����
���ܣ�
	������ʽ ���� + - * / �����֣�
	�����ֺ��ַ�֮���пո�
	������һ����������
	С���㱣��2λ,
	���ʽ��󳤶�200��
	���ʽ��һΪ0ʱ������
*/

/*	
	int getval(char)
	�õ�����������ȼ�
	�����ַ�
	+, -, *, /. 
	��� 1��*, /��
		 0 (+, -)
*/


int getval(char ch)
{
	if (ch == '*' || ch == '/')
	{
		return 1;
	}
	return 0;
}

/*
	int getconse(int,int,char)
	���㵥һ���ʽ���
*/

int getconse(int f, int l, char ch)
{
	if (ch == '+')
		return f + l;
	if (ch == '-')
		return f - l;
	if (ch == '*')
		return f*l;
	if (ch == '/')
		return f / l;
}


int main()
{
	stack<float>snum;
	stack<char>	sch;
	char ch[MAXSIZE];
	while (gets_s(ch,MAXSIZE))
	{
		if (ch[0] == '0'&&ch[1] == 0)//������ʶ
			break;
		for (int i=0;ch[i]!=0;++i)//�����õ����ַ���
		{
			if (ch[i] == ' ')
				continue;
			if (ch[i] >= '0'&&ch[i] <= '9')//���������
			{
				int tnum = 0;
				while (ch[i]!=' '&&ch[i]!=0)
				{
					tnum = tnum * 10;
					tnum += ch[i] - '0';
					++i;
				}
				--i;
				snum.push(tnum);

			}
			else//����������
			{
				if (sch.empty())
					sch.push(ch[i]);
				else if (getval(ch[i]) > getval(sch.top()))//�����ȼ�ֱ����ջ
				{
					sch.push(ch[i]);
				}
				else//�ͻ�������ȼ���ȡ�������ڰѽ����ջ
				{
					int num1 = snum.top();
					snum.pop();
					int num2 = snum.top();
					snum.pop();
					char ch1 = sch.top();
					sch.pop();
					snum.push(getconse(num2, num1, ch1));
					--i;
				}//end else
			}//end else
		}//end for
		while (!sch.empty())//��ʣ��ı��ʽ���ҵ����������
		{
			int num1 = snum.top();
			snum.pop();
			int num2 = snum.top();
			snum.pop();
			char ch1 = sch.top();
			sch.pop();
			snum.push(getconse(num2, num1, ch1));
		}
		printf("%.2f\n", snum.top());
		snum.pop();
	}

	return 0;
}