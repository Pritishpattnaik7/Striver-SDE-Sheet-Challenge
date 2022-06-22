#include<bits/stdc++.h>
using namespace std;

int helper(int i, vector<int> &arr, int s, int sum){
    //base condition
    if (i >= arr.size()){
        if (s == sum) return 1;
        else return 0;
    }
    
    //pick
    s += arr[i];

    int l = helper(i+1, arr, s, sum);
    
    s -= arr[i];
    
    //not pick
    int r = helper(i+1, arr, s, sum);

    return l+r;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    
    int ans = helper(0, arr, 0, k);
    cout << ans;
}