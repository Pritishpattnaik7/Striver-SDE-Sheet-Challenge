#include<bits/stdc++.h>
using namespace std;

void helper(int i, vector<int> &nums, vector<int> &subSet, vector<vector<int>> &powerSet){
        //base cond
        if (i >= nums.size()){
            powerSet.push_back(subSet);
            return;
        }
        
        //pickup
        subSet.push_back(nums[i]);
        helper(i+1, nums, subSet, powerSet);
        subSet.pop_back();
        
        //skip
        while (i+1 < nums.size() and nums[i] == nums[i+1]) i++;
        helper(i+1, nums, subSet, powerSet);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subSet;
        vector<vector<int>> powerSet;
        helper(0, nums, subSet, powerSet);
        sort(powerSet.begin(), powerSet.end());
        return powerSet;
    }

int main(){
}