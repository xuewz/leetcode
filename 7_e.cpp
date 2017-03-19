#include <iostream>
#include <limits.h>
using namespace std;
//实现数字反转，如-123变为-321
class Solution {
public:
    int reverse(int x) {
        int y=0;
        while(x!=0)
        {
            int n=x%10;
            while(y>INT_MAX/10 || y<INT_MIN/10)
            return 0;
            y=y*10+n;
            x/=10;
        }
        return y;
    }
};
int main()
{
	Solution dx;
	int x=-123;
	cout << dx.reverse(x);
	return 0;
}