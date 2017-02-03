#include<stdio.h>
#include<stack>
using std::stack;
#define MAXSIZE 201
int getval(char ch)
{
	if (ch == '*' || ch == '/')
	{
		return 1;
	}
	return 0;
}
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
	stack<int>	snum;
	stack<char>	sch;
	char ch[MAXSIZE];
	while (scanf_s("%s", ch, MAXSIZE) != EOF)
	{
		if (ch[0] == '0'&&ch[1] == 0)
			break;
		for (int i=0;ch[i]!=0;++i)
		{
			if (ch[i] >= '0'&&ch[i] <= '9')
			{
				int tnum = 0;
				while (ch[i++]!=' ')
				{
					tnum = tnum * 10;
					tnum += ch[i] - '0';
				}
				--i;
				snum.push(tnum);

			}
			else
			{
				if (sch.empty())
					sch.push(ch[i]);
				else if (getval(ch[i] > getval(sch.top())))
				{
					sch.push(ch[i]);
				}
				else
				{
					int num1 = snum.top();
					snum.pop();
					int num2 = snum.top();
					snum.pop();
					char ch1 = sch.top();
					int cons = getconse(num2, num1, ch1);
					snum.push(cons);
					--i;
				}//end else
			}//end else
		}//end for
	}
}