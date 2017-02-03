#include<stdio.h>
#include<string>
#include<iostream>
#include<stack>
#define MAXSIZE 101
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::stack;
int main()
{
	char out[MAXSIZE];
	char str[MAXSIZE];
	stack<int> st;
	int i = 0;
	while (scanf_s("%s",str,MAXSIZE) != EOF)
	{
		for (i = 0;str[i] != 0;++i)
		{
			if (str[i] == '(')
			{
				out[i] = ' ';
				st.push(i);
			}
			else if (str[i] == ')')
			{
				if (!st.empty())
				{
					out[i] = ' ';
					st.pop();
				}
				else {
					out[i] = '?';

				}
			}
			else {
				out[i] = ' ';
			}
		}//end for
		while (!st.empty())
		{
			out[st.top()] = '$';
			st.pop();
		}
		out[i] = 0;
		puts(str);
		puts(out);

	}


}