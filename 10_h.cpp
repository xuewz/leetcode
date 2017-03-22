#include <iostream>
#include <string>

using namespace std;
/*
����ƥ�����⣺
*��ʾ֮ǰ�ַ��������
�ּ������������sƥ��p
1.pΪ�գ�sҲΪ�գ�����
2.p��s���ȶ�Ϊ1����ͬ����pΪ.����
3.p[1]��Ϊ*,sΪ����٣�s��Ϊ��ʱ������2�ж����ַ��Ƿ�ƥ�䣬
���Ҵӵ�2���ַ���ʼ���õݹ�ƥ��
4.p[1]Ϊ*��s��Ϊ�������ַ�ƥ�䣬���õݹ��p[2]��sƥ��,��ƥ��Ϊ�棬
�����s[1]��ʼƥ��(�о����������е���)
5.���ص��õݹ�ƥ��s��p[2]��ʼ�Ľ����
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
