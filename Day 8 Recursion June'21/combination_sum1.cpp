#include<bits/stdc++.h>
using namespace std;

void helper(int i, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans){
    //base condition
    if (i >= arr.size()){
        if (target == 0){
            ans.push_back(ds);
        }
        return;
    }

    //pick up the ith ele
    if (arr[i] <= target){
        ds.push_back(arr[i]);
        helper(i, target-arr[i], arr, ds, ans);
        ds.pop_back();
    }

    //not pick
    helper(i+1, target, arr, ds, ans);
}

vector<vector<int>> combinationSum(vector<int> &arr, int target){
    vector<vector<int>> ans;
    vector<int> ds;
    helper(0, target, arr, ds, ans);
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
    int target;
    cin >> target;

    vector<vector<int>> ans = combinationSum(arr, target);
    for (auto x : ans){
        for (auto y : x){
            cout << y << " ";
        }
        cout << endl;
    }
}