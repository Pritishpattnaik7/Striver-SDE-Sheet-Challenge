#include<bits/stdc++.h>
using namespace std;

//*********Brute force solution**************
void setZerosBrute(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();

    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            if (mat[i][j] == 0){

                int idx = i-1;
                while (idx >= 0){
                    if (mat[idx][j] != 0){
                        mat[idx][j] = -1;
                    }
                    idx--;
                }

                idx = i+1;
                while (idx < n){
                    if (mat[idx][j] != 0){
                        mat[idx][j] = -1;
                    }
                    idx++;
                }

                idx = j-1;
                while (idx >= 0){
                    if (mat[i][idx] != 0){
                        mat[i][idx] = -1;
                    }
                    idx--;
                }

                idx = j+1;
                while (idx < m){
                    if (mat[i][idx] != 0){
                        mat[i][idx] = -1;
                    }
                    idx++;
                }
            }
        }
    }

    //Then we will traverse the matrix again and change the all -1s to 0
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            if (mat[i][j] == -1){
                mat[i][j] = 0;
            }
        }
    }

    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}


//********Optimized Solution********
void setZeroes(vector<vector<int>> mat){
    //take 2 dummy arrays
    int n = mat.size();
    int m = mat[0].size();
    vector<int> row(n, -1), col(n, -1);
    
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            if (mat[i][j] == 0){
                row[i] = 0;
                col[j] = 0;
            }
        }
    }

    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            if (row[i] == 0 or col[i] == 0){
                mat[i][j] == 0;
            }
        }
    }

    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
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

    setZerosBrute(mat);
}