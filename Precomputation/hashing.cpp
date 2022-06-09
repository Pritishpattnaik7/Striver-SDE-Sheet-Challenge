/*
HASHING
Given an array of n integers, given q queries
in each query given a number x , print the 
count of that number in the array

Constraints
1 <= n <= 10^5
1 <= q <= 10^5
1 <= arr[i] <= 10^7

*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e7+10;
int hsh[N];

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i=0 ; i<n ; i++){
        cin >> arr[i];
        hsh[arr[i]]++;
    }
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        cout << hsh[x] << endl;
    }
    //old tc -> O(q*n) -> O(n^2) = 10^10(will not work in 1sec -> TLE)
    //new tc -> O(q) + O(n) => O(n) => 2*10^5
    return 0;
}