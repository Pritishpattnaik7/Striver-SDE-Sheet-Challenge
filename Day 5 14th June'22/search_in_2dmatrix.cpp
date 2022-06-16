#include<bits/stdc++.h>
using namespace std;

//brute force o(n*m)
bool searchMatrixBrute(vector<vector<int>> &mat, int target){
    int n = mat.size(), m = mat[0].size();
    bool flag = false;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            if (mat[i][j] == target){
                flag = true;
            }
        }
    }
    return flag;
}

//approach 2
bool searchMatix(vector<vector<int>> &mat, int target){
    int n = mat.size(), m = mat[0].size();
    int i=0, j=m-1;
    while (i<n and j>=0){
        if (mat[i][j] == target){
            return true;
        }
        else if (target < mat[i][j]){
            j--;
        }
        else if (target > mat[i][j]){
            i++;
        }
    }
    return false;
}

//approach 3 => binary search
bool searchMatrixBinarySearch(vector<vector<int>> &mat, int target){
    int n = mat.size(), m = mat[0].size();
    if (!mat.size()) return false;

    int lo = 0;
    int hi = (n*m)-1;

    while (lo <= hi){
        int mid = (lo + (hi - lo) / 2);
        if (mat[mid/m][mid%m] == target){
            return true;
        }
        if (mat[mid/m][mid%m] < target){
            lo = mid+1;
        }
        else {
            hi = mid-1;
        }
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int> (m));
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin >> mat[i][j];
        }
    }
    int target;
    cin >> target;

    if (searchMatrixBinarySearch(mat, target)){
        cout << "element found\n";
    }
    else {
        cout << "element NOT found\n";
    }
}