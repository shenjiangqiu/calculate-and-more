#include<stdio.h>
#include<stack>
using std::stack;
#define MAXSIZE 201
/*
作者 申江秋（ivy22233qiu@live.com)
名称 简易计算器
功能：
	输入表达式 包含 + - * / 和数字，
	在数字和字符之间有空格，
	结果输出一个浮点数，
	小数点保留2位,
	表达式最大长度200，
	表达式单一为0时结束。
*/

/*	
	int getval(char)
	得到运算符的优先级
	输入字符
	+, -, *, /. 
	输出 1（*, /）
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
	计算单一表达式结果
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
		if (ch[0] == '0'&&ch[1] == 0)//结束标识
			break;
		for (int i=0;ch[i]!=0;++i)//遍历得到的字符串
		{
			if (ch[i] == ' ')
				continue;
			if (ch[i] >= '0'&&ch[i] <= '9')//如果是数字
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
			else//如果是运算符
			{
				if (sch.empty())
					sch.push(ch[i]);
				else if (getval(ch[i]) > getval(sch.top()))//高优先级直接入栈
				{
					sch.push(ch[i]);
				}
				else//低或相等优先级则取出运算在把结果入栈
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
		while (!sch.empty())//把剩余的表达式从右到左计算出结果
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