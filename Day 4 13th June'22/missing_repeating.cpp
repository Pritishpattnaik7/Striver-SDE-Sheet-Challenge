#include<bits/stdc++.h>
using namespace std;

//using a hash array
vector<int> find_missing_repeating(vector<int> arr){
    int n = arr.size();
    vector<int> hsh(n+1, 0), ans;
    
    for (int i=0 ; i<n ; i++){
        hsh[arr[i]]++;
    }

    for (int i=1 ; i<hsh.size() ; i++){
        if (hsh[i] == 0 or hsh[i] > 1){
            ans.push_back(i);
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0 ; i<n ; i++){
        cin >> nums[i];
    }

    vector<int> ans = find_missing_repeating(nums);
    for (auto x : ans){
        cout << x << " ";
    }
}