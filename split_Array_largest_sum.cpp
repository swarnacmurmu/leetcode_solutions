#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int count(vector<int>& nums, int mid){
        int n = nums.size();
        int noofarr = 1;
        long long subarr = 0;

        for(int i = 0; i < n; i++){
            if(subarr + nums[i] <= mid){
                subarr += nums[i];
            }
            else{
                noofarr += 1;
                subarr = nums[i];
            }
        }
        return noofarr;
    }

    int splitArray(vector<int>& nums, int k){
        int low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);

        while(low <= high){
            int mid = (low + high) / 2;
            int noofarr = count(nums, mid);

            if(noofarr > k) low = mid + 1;
            else high = mid - 1;
        }

        return low;
    }
};

int main(){
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;

    Solution obj;
    int result = obj.splitArray(nums, k);

    cout << "Minimum Largest Sum: " << result << endl;

    return 0;
}