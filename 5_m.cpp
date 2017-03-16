#include <iostream>

using namespace std;
/*
���ö�̬�滮����𣬸��Ӷ�O(n^2)
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
                if(dp[j][i]&&len<i-j+1)//len<i-j+1��֤��һ�����
                {
                    len=i-j+1;
                    l=j;
                    r=i;
                }
            }
            dp[i][i]=1;
        }
        return s.substr(l,r-l+1);//�����len����©��һ����ĸ�����
    }
};*/
/*
������ÿ���ַ������Ҷ�����#��Ϊ��ֹ���Ҷ���#,�ײ����Ϸ�#,ĩβ\0
p[i]��ʾ��t[i]�ַ�Ϊ���ĵĻ����Ӵ��İ뾶��
��p[i] = 1����û����Ӵ�����t[i]����
idΪ�������Ӵ����ĵ�λ�ã�mx��ʾ��뾶
������������е㲻����������ø��Ӷ���O(n)
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