#include <iostream>
#include <string>
#include <map>
using namespace std;
/*
��������ĸת�������֣�
1.�����������ַ�����Ž�map�У�
2.����������ַ�������λ��ʼ�жϣ������ǰ��ĸֵС����һ�����ʹӽ����ȥ��ֵ��
������ϸ�ֵ��
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