#include <iostream>

using namespace std;
//˼·�Ƚϼ򵥣������жϴ���0�������ַ�ת�Ƿ����ԭ��
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