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
			//����һ��ʼû�뵽m[s[i]]<left���ϱ������ǲ�ֹ��һ����Ļ�ظ���
		    //�Ӵ����滹���ظ���
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