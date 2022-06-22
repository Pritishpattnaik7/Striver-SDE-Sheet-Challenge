//print ONLY 1 subset with sum = k
#include<bits/stdc++.h>
using namespace std;

bool helper(int i, vector<int> &arr, int s, int sum, vector<int> &subSet){
    //base condition
    if (i >= arr.size()){
        if (s == sum){
            for (auto x : subSet){
                cout << x << " ";
            }
            cout << endl;
            return true;
        }
        else{
            return false;
        }
    }
    
    //pick
    subSet.push_back(arr[i]);
    s += arr[i];

    if (helper(i+1, arr, s, sum, subSet) == true) return true; 
    
    subSet.pop_back();
    s -= arr[i];
    
    //not pick
    if (helper(i+1, arr, s, sum, subSet) == true) return true;

    return false;
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