#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0, cur_cnt = 0;
        for (int i=0 ; i<nums.size() ; i++){
            if (nums[i] == 1){
                cur_cnt++;
            }
            else {
                cur_cnt = 0;
            }
            maxi = max(maxi, cur_cnt);
        }
        return maxi;
}

int main(){
}