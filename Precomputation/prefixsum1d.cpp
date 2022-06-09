//prefix sum 1d array
/*
Given an array of size N , given Q queries
and in each query given L and R , 
print the sum of elements from index L to R

Constraints
1 <= n <= 10^5
1 <= q <= 10^5
1 <= arr[i] <= 10^9
1 <=L,R <=n

*/
//TAKE 1 BASED ARRAY
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int arr[N];
int pf[N];

int main(){
    int n;
    cin >> n;
    for (int i=1 ; i<=n ; i++){
        cin >> arr[i];
        pf[i] = pf[i-1] + arr[i];    //calculate the prefix sum array
    }
    int q;
    cin >> q;
    while (q--){
        int l, r;
        cin >> l >> r;
        cout << pf[r] - pf[l-1] << endl;
    }

    //old tc -> O(n) + O(q*n) => O(n^2) => 10^10
    //new tc -> O(n) + O(q) => O(n) => 10^5
    return 0;
}
