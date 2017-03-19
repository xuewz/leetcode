#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

//ʵ��atoi��
/*
1.����Ϊ���ַ�������0��
2.ǰ׺�Ӳ�Ϊ0���ַ�����ʼ��
3.+��-����
4����һ���ַ�Ϊ�����ַ���0�������м����ַ�Ϊ�����ַ��ص�ǰ����
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