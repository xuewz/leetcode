#include <iostream>
#include <string>

using namespace std;
/*
通配符匹配问题：
*表示之前字符任意个数
分几种情况：假设s匹配p
1.p为空，s也为空，则真
2.p、s长度都为1，相同或者p为?则真
3.p[0]为*,去掉首字符，s为空则假，s不为空时，递归判断匹配，不匹配去掉首字符继续匹配，
4.p[0]不为*，s不为空且首字符匹配，调用递归p和s匹配。
5.返回调用递归匹配s和p[2]开始的结果。
*/
/*class Solution{
	public:
	bool isMatch(string s,string p)
	{
		if( s.empty())
		{
			if(p.empty())return 1;
			if(p[0]!='*')return 0;
		}
		if(p[0]=='*')
		{
			while(p[0]=='*')
				p=p.substr(1);
			while(!s.empty())
			{
				if(isMatch(s,p))return 1;
				s=s.substr(1);
			}
			return (isMatch(s,p));
		}
		else if((!s.empty()&&p[0]=='?'||s[0]==p[0])
		{
			return (isMatch(s.substr(1),p.substr(1)));

		}
		return 0;
	}
};*///递归会超时。。。
/*通配符匹配：
1,首先从s的每个字符开始检查，若p不为空并且p[j]为？或者p[j]等于s[i],继续递增j,i;
否则判断p是否为空且p[j]是否等于*,等于则记录j为jInd，i为iInd，递增j,即匹配0个字符；
否则判断jInd是否为-1，不是说明前面有*，跳到*的下一个位置开始回溯s,
即j=jInd+1,i=iInd+1,iInd++;(这里不太好想，怎样确定i和iInd的位置很关键)；
否则返回0；
2.判断剩余p都为*返回1；
*/
class Solution {  
public:  
    bool isMatch(string s, string p) {  
        int i = 0,j = 0;  
        int jInd = -1,iInd = -1;    
        while (i < s.size()) {  
            if (j < p.size() && (p[j] == '?' || p[j] == s[i])) { // match  
                ++i;  
                ++j;  
            } else if (j < p.size() && p[j] == '*') {  
                jInd = j; // 记录*的位置  
                iInd = i; // 记录i的位置  
                j++; // 从j下一个位置进行匹配, *匹配了0个字符  
            } else if (jInd != -1) { // 如果之前有*出现过，则回溯  
                j = jInd + 1; // 重置j的位置  
                i = iInd+1;  
                iInd++; // *匹配1,2,3,4,5...个字符  
            } else {  
                return 0; // 不match，return false  
            }       
        }  
        while (j < p.size() && p[j] == '*') { // 看p剩下的字符是不是都是*  
            ++j;   
        }    
        return j == p.size();   
    }             
};  
int main()
{
	Solution dx;
	string s="aabc";
	string p="a*";
	cout << dx.isMatch(s,p) << endl;
	return 0;
}
