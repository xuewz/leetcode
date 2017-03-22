#include <iostream>
#include <string>
#include <map>
using namespace std;
/*
将罗马字母转换成数字：
1.将单个罗马字符种类放进map中，
2.输入的罗马字符串从首位开始判断，如果当前字母值小于下一个，就从结果减去该值，
否则加上该值。
*/
class Solution{
	public:
	int romanToInt(string s)
	{
		map<char,int> map={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
		int ans=0;
		for(int i=0;i<s.size();++i)
		{
			if((i<s.size())&&(map[s[i]]<map[s[i+1]]))
				ans-=map[s[i]];
			else
				ans+=map[s[i]];
		}
		return ans;
	}	
};
int main()
{
	Solution dx;
	string s="IV";
	cout << dx.romanToInt(s);
	return 0;
}