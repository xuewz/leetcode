#include <iostream>
#include <string>
using namespace std;
/*
根据规则，如果有n行ZigZag,s[],i:0-n
第一行：索引值：0,0+(n-1)*2,...
2:1,1+（n-1）*2-2*i,1+（n-1）*2-2*i+2*i,...
..
n-1:n-1,n-1+2*i,...
所以可以设置一个move[2],特别处理第一行和最后一行
*/
class Solution {
public:
	string convert(string s, int numRows)
	{
		if (numRows <= 1)return s;
		int ind = 0;
		string t(s.size(),'\0');
		for (int i = 0; i< numRows; i++)
		{
			int move[2] = { (numRows - 1) * 2 - 2 * i,2 * i };
			if (i == 0)move[1] = (numRows - 1) * 2;
			if (i == numRows-1)move[0] = 2 * i;
			int c = 0;
			int ii = i;
			while (ii< s.size())
			{
				t[ind++] = s[ii];
				ii += move[(c++) % 2];
			}
		}
		return t;
	}
};

int main()
{
	Solution dx;
	string s = "PAYPALISHIRING";
	int numRows = 3;
	cout << dx.convert(s, numRows);
	return 0;
}