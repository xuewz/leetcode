#include <iostream>
#include <string>

using namespace std;
/*
ͨ���ƥ�����⣺
*��ʾ֮ǰ�ַ��������
�ּ������������sƥ��p
1.pΪ�գ�sҲΪ�գ�����
2.p��s���ȶ�Ϊ1����ͬ����pΪ?����
3.p[0]Ϊ*,ȥ�����ַ���sΪ����٣�s��Ϊ��ʱ���ݹ��ж�ƥ�䣬��ƥ��ȥ�����ַ�����ƥ�䣬
4.p[0]��Ϊ*��s��Ϊ�������ַ�ƥ�䣬���õݹ�p��sƥ�䡣
5.���ص��õݹ�ƥ��s��p[2]��ʼ�Ľ����
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
};*///�ݹ�ᳬʱ������
/*ͨ���ƥ�䣺
1,���ȴ�s��ÿ���ַ���ʼ��飬��p��Ϊ�ղ���p[j]Ϊ������p[j]����s[i],��������j,i;
�����ж�p�Ƿ�Ϊ����p[j]�Ƿ����*,�������¼jΪjInd��iΪiInd������j,��ƥ��0���ַ���
�����ж�jInd�Ƿ�Ϊ-1������˵��ǰ����*������*����һ��λ�ÿ�ʼ����s,
��j=jInd+1,i=iInd+1,iInd++;(���ﲻ̫���룬����ȷ��i��iInd��λ�úܹؼ�)��
���򷵻�0��
2.�ж�ʣ��p��Ϊ*����1��
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
                jInd = j; // ��¼*��λ��  
                iInd = i; // ��¼i��λ��  
                j++; // ��j��һ��λ�ý���ƥ��, *ƥ����0���ַ�  
            } else if (jInd != -1) { // ���֮ǰ��*���ֹ��������  
                j = jInd + 1; // ����j��λ��  
                i = iInd+1;  
                iInd++; // *ƥ��1,2,3,4,5...���ַ�  
            } else {  
                return 0; // ��match��return false  
            }       
        }  
        while (j < p.size() && p[j] == '*') { // ��pʣ�µ��ַ��ǲ��Ƕ���*  
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
