#include<bits/stdc++.h>
using namespace std;

void helper(int i, vector<int> &arr, int s, int sum, vector<int> &subSet){
    //base condition
    if (i >= arr.size()){
        if (s == sum){
            for (auto x : subSet){
                cout << x << " ";
            }
            cout << endl;
        }
        return;
    }
    
    //pick
    subSet.push_back(arr[i]);
    s += arr[i];

    helper(i+1, arr, s, sum, subSet);
    
    subSet.pop_back();
    s -= arr[i];
    
    //not pick
    helper(i+1, arr, s, sum, subSet);
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
    
    vector<int> subSet;
    helper(0, arr, 0, k, subSet);
}