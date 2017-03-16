#include <iostream>

using namespace std;
/*
采用动态规划来解答，复杂度O(n^2)
*/
/*class Solution {
public:
    string longestPalindrome(string s) {
        int dp[s.size()][s.size()]={0},l=0,r=0;
        int len=0;
        for(int i=0;i<s.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                dp[j][i]=(s[i]==s[j] &&(i-j<2 || dp[j+1][i-1]));
                if(dp[j][i]&&len<i-j+1)//len<i-j+1保证第一个最长的
                {
                    len=i-j+1;
                    l=j;
                    r=i;
                }
            }
            dp[i][i]=1;
        }
        return s.substr(l,r-l+1);//如果用len，会漏掉一个字母的情况
    }
};*/
/*
首先在每个字符串左右都加上#，为防止左右都是#,首部加上非#,末尾\0
p[i]表示以t[i]字符为中心的回文子串的半径，
若p[i] = 1，则该回文子串就是t[i]本身
id为最大回文子串中心的位置，mx表示其半径
这个方法还是有点不懂，但是最好复杂度是O(n)
*/
class Solution {
public:
string longestPalindrome(string s) {
        string t ="$#";
        for (int i = 0; i < s.size(); ++i) {
            t += s[i];
            t += '#';
        }
        int p[t.size()] = {0}, id = 0, mx = 0, resId = 0, resMx = 0;
        for (int i = 0; i < t.size(); ++i) {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while (t[i + p[i]] == t[i - p[i]]) ++p[i];
            if (mx < i + p[i]) {
                mx = i + p[i];
                id = i;
            }
            if (resMx < p[i]) {
                resMx = p[i];
                resId = i;
            }
        }
        return s.substr((resId - resMx) / 2, resMx - 1);
	}
};
int main()
{
	Solution dx;
	string s="babad";
	cout << dx.longestPalindrome(s)<<endl;
	return 0;
}