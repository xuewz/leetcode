#include <iostream>
#include <vector>
using namespace std;
/*�ҵ����������������
����n���Ǹ���������ʾn���߶Σ�ÿ���߶����˶˵�Ϊ0�͸���ֵ��С��
1.����ѡȡ���������������ȡ������֮����Сֵ��Ϊ�ߣ���������֮����Ϊ�ף���Ϊl=0,r=n-1;
2.���height[l]С��height[r],l++����֮����
3.ֱ��L==r�����ϸ������������
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
		int l=0,r=height.size()-1;
		int ans=0;
		while(l<r)
		{
			int t=min(height[l],height[r]);
			ans= max(ans,t*(r-l));
			if(height[l]<height[r])
			{
				l++;
			}
			else
				r--;
		}
		return ans;
    }
};
int main()
{
	Solution dx;
	vector<int> height;
	int t;
	while(cin >> t)
		height.push_back(t);
	cout << dx.maxArea(height)<< endl;
	return 0;
}