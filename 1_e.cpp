#include <iostream>
#include <vector>
#include <map>
/*
Two sum
最简单的方法是在i,i+1,...,nums.size()-1寻找target-nums[i],
但是最坏情况下O(n^2)
改进思路：利用map，hash查找O(1)
如果找到(target-nums[i]),直接返回i和indMap[(target-nums[i])]，
应该是O(n)
*/
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> indMap;
		vector<int>ans;
		int t;
		for (int i = 0; i<nums.size(); ++i)
			indMap[nums[i]] = i;
		for (int i = 0; i<nums.size(); ++i)
		{
			t = target - nums[i];
			if (indMap.find(t) != indMap.end() && indMap[t] != i)
			{
				ans.push_back(i);
				ans.push_back(indMap[t]);
				return ans;
			}
		}
		return ans;
	}
};

int main()
{
	Solution dx;
	vector<int> nums{2,7,11,15};
	int target=9;
	vector<int> ans;
	ans = dx.twoSum(nums,target);
	cout << ans[0] << " " << ans[1];
	return 0;
}
