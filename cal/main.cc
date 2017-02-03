#include<stdio.h>
#include<stack>
using std::stack;
#define MAXSIZE 201
int main()
{
	stack<int>	snum;
	stack<int>	sch;
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
				int tmpch = 0;
				if (ch[i] == '*' || ch[i] == '/')
				{
					tmpch = 1;
				}
				else
				{
					tmpch = 0;
				}
				if (sch.empty())
					sch.push(tmpch);
				else
				{

				}
			}
		}
	}
}