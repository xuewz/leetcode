#include <iostream>

using namespace std;
//思路比较简单：首先判断大于0，对数字翻转是否等于原数
class Solution
{
	public:
	bool isPalindrome(int x)
	{
		if(x<0)return 0;
		int t=x;
		int sum=0;
		while(x!=0)
		{
			sum=sum*10+x%10;
			x/=10;
		}
		if(t==sum)
			return 1;
		else
			return 0;
	}
};
int main()
{
	Solution dx;
	int x;
	cin>>x;
	cout << dx.isPalindrome(x);
	return 0;
}