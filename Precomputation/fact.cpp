/*
Given t testcases and in each testcase a number n, 
print it's factorial for each testcase % m
where m = 1e9+7

Constraints
1 <= n <= 10^5
1 <= t <= 10^5

*/
#include<bits/stdc++.h>
using namespace std;

const int m = 1e9+7;
const int N = 1e5+10;
long long factarr[N];

int main(){
    //here we compute the fact of all numbers at first , then we can use them later
    factarr[0] = factarr[1] = 1;
    for (int i=2 ; i<N  ; i++){
        factarr[i] = factarr[i-1] * i;
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << factarr[n] << endl;
    }
    //here we reduced the time complexity from O(t*n)/O(n^2) to  O(n) + O(t) = O(n)
    return 0;
}