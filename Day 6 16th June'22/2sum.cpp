#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        map<int, int> mp;
        for (int i=0 ; i<n; i++){
            int temp = target-nums[i];
            if (mp.find(temp) == mp.end()){
                mp.insert({nums[i], i});
            }
            else {
                ans.push_back(mp[temp]);
                ans.push_back(i);
            }
        }
        return ans;
    }

int main(){
}