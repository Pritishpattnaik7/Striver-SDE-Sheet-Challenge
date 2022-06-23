//Unique permutations , leetcode permutations ii
#include<bits/stdc++.h>
using namespace std;

void helper(vector<int> &nums, vector<int> &ds, set<vector<int>> &ans, vector<int> &freq){
        //base condition
        if (ds.size() == nums.size()){
            ans.insert(ds);
            return;
        }
        
        for (int i=0 ; i<nums.size() ; i++){
            if (freq[i] == 0){
                ds.push_back(nums[i]);
                freq[i] = 1;
                helper(nums, ds, ans, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> freq(nums.size(), 0);
        set<vector<int>> ans;
        vector<int> ds;
        
        helper(nums, ds, ans, freq);
        vector<vector<int>> finalAns(ans.begin(), ans.end());
        return finalAns;
    }

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0 ; i<n ; i++){
        cin >> nums[i];
    }

    vector<vector<int>> ans = permuteUnique(nums);
    for (auto x : ans){
        for (auto y : x){
            cout << y << " ";
        }
        cout << endl;
    }
}