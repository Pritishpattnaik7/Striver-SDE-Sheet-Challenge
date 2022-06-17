//max subarray with sum 0
#include<bits/stdc++.h>
using namespace std;

int longestSubArr(vector<int> &arr){
    map<int, int> mp;
    int sum = 0, maxi = 0;
    for (int i=0 ; i<arr.size() ; i++){
        sum += arr[i];
        if (sum == 0){
            maxi = i+1;
        }
        else {
            if (mp.find(sum) != mp.end()){
                maxi = max(maxi, i - mp[sum]);
            }
            else {
                mp.insert({sum, i});
            }
        }
    }
    return maxi;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0 ; i<n ; i++){
        cin >> nums[i];
    }

    int ans = longestSubArr(nums);
    cout << ans;
}