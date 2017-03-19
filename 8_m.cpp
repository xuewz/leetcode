#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

//实现atoi，
/*
1.输入为空字符，返回0，
2.前缀从不为0的字符串开始，
3.+，-保留
4，第一个字符为非数字返回0，或者中间有字符为非数字返回当前数字
*/
class Solution{
public:
	int myAtoi(string s)
	{
			int flag = 1;
			long long ans = 0;
			int i = 0;
			if (s.empty())return ans;
			while (i < s.size() && s[i] == ' ')
				++i;
			if (s[i] == '+')
			{
				flag = 1;
				++i;
			}
			else if (s[i] == '-')
			{
				flag = -1;
				++i;
			}
			while (i < s.size())
			{
				if (s[i] <= '9' && s[i] >= '0')
					ans = ans * 10 + flag*(s[i] - '0');
				else
					return ans;
				if (ans > INT_MAX || ans < INT_MIN)return (ans>0) ? INT_MAX : INT_MIN;
				++i;
			}
			return ans;
	}
};

int main()
{
	Solution dx;
	string s = "  a123";
	cout << dx.myAtoi(s);
	return 0;
}