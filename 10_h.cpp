#include <iostream>
#include <string>

using namespace std;
/*
正则匹配问题：
*表示之前字符任意个数
分几种情况：假设s匹配p
1.p为空，s也为空，则真
2.p、s长度都为1，相同或者p为.则真
3.p[1]不为*,s为空则假，s不为空时，根据2判断首字符是否匹配，
并且从第2个字符开始调用递归匹配
4.p[1]为*，s不为空且首字符匹配，调用递归从p[2]和s匹配,若匹配为真，
否则从s[1]开始匹配(感觉还是这里有点绕)
5.返回调用递归匹配s和p[2]开始的结果。
*/
class Solution{
	public:
	bool isMatch(string s,string p)
	{
		if(p.empty())return s.empty();
		if(p.size()==1 && s.size()==1)
			return (s[0]==p[0]||p[0]=='.');
		if(p[1]!='*')
		{
			if(s.empty())return 0;
			return (s[0]==p[0]||p[0]=='.')&&isMatch(s.substr(1),p.substr(1));
		}
		while(!s.empty()&&(s[0]==p[0]||p[0]=='.'))
		{
			if(isMatch(s,p.substr(2)))return 1;
			s=s.substr(1);
		}
		return isMatch(s,p.substr(2));
	}
};
int main()
{
	Solution dx;
	string s="a";
	string p=".*";
	cout << dx.isMatch(s,p) << endl;
	return 0;
}
