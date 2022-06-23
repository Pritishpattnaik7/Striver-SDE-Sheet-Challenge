#include<bits/stdc++.h>
using namespace std;

void helper(vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, vector<int> &freq){
    //base condition
    if (ds.size() == nums.size()){
        ans.push_back(ds);
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

vector<vector<int>> permute(vector<int> &nums){
    vector<int> freq(nums.size(), 0);
    vector<vector<int>> ans;
    vector<int> ds;

    helper(nums, ds, ans, freq);
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0 ; i<n ; i++){
        cin >> nums[i];
    }

    vector<vector<int>> ans = permute(nums);
    for (auto x : ans){
        for (auto y : x){
            cout << y << " ";
        }
        cout << endl;
    }
}