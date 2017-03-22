#include <iostream>
#include <string>
using namespace std;
/*
������ת��Ϊ�������֣������������ֹ���
�Ƚ����ֺ�����������ִ�С����������������϶�Ӧ��ĸ��ֱ������Ϊ��
*/
class Solution{
	public:
	string intToRoman(int num)
	{
		int digit[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
		string Roman[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
		string ans="";
		int i=0;
		while(num!=0)
		{
			if(num>=digit[i])
			{
				num-=digit[i];
				ans+=Roman[i];
			}
			else
			    i++;
		}
		return ans;
	}
};
int main()
{
	Solution dx;
	int num=101;
	cout << dx.intToRoman(num);
	return 0;
}