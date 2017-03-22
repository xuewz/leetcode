#include <iostream>
#include <vector>
using namespace std;
/*找到最大容量的容器：
给定n个非负整数，表示n条线段，每条线段两端端点为0和该数值大小；
1.假设选取数组两端求面积，取两个数之间最小值作为高，两个索引之差作为底，记为l=0,r=n-1;
2.如果height[l]小于height[r],l++；反之。。
3.直到L==r，不断更新最大的面积。
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