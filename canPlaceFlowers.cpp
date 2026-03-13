#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int s = flowerbed.size();

        for(int i = 0; i < s; i++) {
            if(flowerbed[i] == 0 &&
               (i == 0 || flowerbed[i-1] == 0) &&
               (i == s-1 || flowerbed[i+1] == 0)) {

                flowerbed[i] = 1;
                count++;

                if(count >= n)
                    return true;
            }
        }

        return count >= n;
    }
};

int main() {

    int size;
    cin >> size;

    vector<int> flowerbed(size);

    for(int i = 0; i < size; i++) {
        cin >> flowerbed[i];
    }

    int n;
    cin >> n;

    Solution obj;

    if(obj.canPlaceFlowers(flowerbed, n))
        cout << "true"<<endl;
    else
        cout << "false"<<endl;

    return 0;
}