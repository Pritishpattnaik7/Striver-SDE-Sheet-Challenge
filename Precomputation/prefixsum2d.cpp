//prefix sum 2d array
/*
Given a 2d array of NxN integers.Given Q queries, 
in each query given a, b, c, d print sum from (a,b) to
(c,d)

Constraints
1 <= N <= 10^3
1 <= Q <= 10^5
1 <= a[i][j] <= 10^9
1 <= a, b,c,d <= N

*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
int arr[N][N];
long long pf[N][N];

int main(){
    int n;
    cin >> n;
    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=n ; j++){
            cin >> arr[i][j];
            //here we calculate the prefix sum by formula
            pf[i][j] = arr[i][j] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];
        }
    }
    int q;
    cin >> q;
    while(q--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        // int sum = 0;
        // for (int i=a ; i<=c ; i++){
        //     for (int j=b ; j<=d ; j++){
        //         sum += arr[i][j];
        //     }
        // }
        // cout << sum << endl;
        cout << pf[c][d] - pf[a-1][d] - pf[c][b-1] + pf[a-1][b-1] << endl;
    }
    return 0;
}