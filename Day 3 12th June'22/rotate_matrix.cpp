#include<bits/stdc++.h>
using namespace std;

//brute force sol
vector<vector<int>> rotateMatrixBrute(vector<vector<int>> &mat, int n, int m){
    vector<vector<int>> rotate(n, vector<int> (m, 0));
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            rotate[j][n-i-1] = mat[i][j];
        }
    }
    return rotate;
}

//optimized sol
vector<vector<int>>  rotateMatrix(vector<vector<int>> &mat, int n, int m){
    //first find the transpose
    vector<vector<int>> rotated(n, vector<int> (m, 0));
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            rotated[i][j] = mat[j][i];
        }
    }

    //then reverse each row
    for (int i=0 ; i<n ; i++){
        reverse(rotated[i].begin(), rotated[i].end());
    }

    return rotated;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int> (m, 0));
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> ans = rotateMatrix(mat, n, m);
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}