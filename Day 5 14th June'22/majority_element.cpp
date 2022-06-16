#include<bits/stdc++.h>
using namespace std;

//hashmap approach
int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for (auto x : nums){
            mp[x]++;
        }
        
        int maxi = 0;
        int ans;
        for (auto it : mp){
            if (it.second > maxi){
                maxi = it.second;
                ans = it.first;
            }
        }
        return ans;
}

//moore voting algo => o(1) space
int majorityElementOpt(vector<int> &nums){
    int n = nums.size();
    int cnt = 0, ele = 0;
        for (int i=0 ; i<n ; i++){
            if (cnt == 0){
                ele  = nums[i];
            }
            if (ele == nums[i]){
                cnt++;
            }
            else {
                cnt--;
            }
        }
        return ele;   
}

int main(){
}