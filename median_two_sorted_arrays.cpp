#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        int n1 = nums1.size(), n2 = nums2.size();
        int i = 0, j = 0;

        while(i < n1 && j < n2){
            if(nums1[i] < nums2[j]) nums3.push_back(nums1[i++]);
            else nums3.push_back(nums2[j++]);
        }

        while(i < n1) nums3.push_back(nums1[i++]);
        while(j < n2) nums3.push_back(nums2[j++]);

        int n = n1 + n2;

        if(n % 2 == 1){
            return nums3[n/2];
        }
        else{
            return ((double)nums3[n/2] + (double)nums3[n/2 - 1]) / 2.0;
        }
    }
};

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    Solution obj;
    double median = obj.findMedianSortedArrays(nums1, nums2);

    cout << "Median: " << median << endl;

    return 0;
}