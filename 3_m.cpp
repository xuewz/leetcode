#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int ans=0,left=0,m[256]={0};
		for(int i=0;i<s.size();++i)
		{
			if(m[s[i]]==0 || m[s[i]]<left)
			//这里一开始没想到m[s[i]]<left，老报错，忘记不止第一个字幕重复，
		    //子串里面还有重复的
			{
				ans=max(ans,i-left+1);
			}
			else
			{
				left=m[s[i]];
			}
			m[s[i]]=i+1;
		}
		return ans;
        
    }
};

int main()
{
	Solution dx;
	string s("abcabcbb");
	cout << dx.lengthOfLongestSubstring(s);
	return 0;
}