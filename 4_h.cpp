#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1=nums1.size(),l2=nums2.size();
        int len=l1+l2;
        if(len & 1)
        return findKth(nums1,0,nums2,0,len/2+1);
        else
        return (findKth(nums1,0,nums2,0,len/2)+findKth(nums1,0,nums2,0,len/2+1))/2;
    }
        double findKth(vector<int>&nums1,int i1,vector<int>&nums2,int i2,int k)
        {
            if(i1>=nums1.size())
            return nums2[i2+k-1];//这里不是k/2
            if(i2>=nums2.size())
            return nums1[i1+k-1];
            if(k==1)
            return min(nums1[i1],nums2[i2]);
            int k1=i1+k/2-1>=nums1.size() ? INT_MAX :nums1[i1+k/2-1];
            int k2=i2+k/2-1>=nums2.size() ? INT_MAX :nums2[i2+k/2-1];
            if(k1<k2)
            {
                return findKth(nums1,i1+k/2,nums2,i2,k-k/2);
            }
            else
            return findKth(nums1,i1,nums2,i2+k/2,k-k/2);
		}
};

int main()
{
	Solution dx;
	vector<int> num1,num2;
	num1.push_back(1);num1.push_back(2);
	num2.push_back(3);num2.push_back(4);
	cout << dx.findMedianSortedArrays(num1,num2);
	return 0;
}

      
	  