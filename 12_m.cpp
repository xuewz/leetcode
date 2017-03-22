#include <iostream>
#include <string>
using namespace std;
/*
将数字转换为罗马数字，根据罗马数字规则：
比较数字和最大罗马数字大小，依次相减，并加上对应字母，直到数字为零
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