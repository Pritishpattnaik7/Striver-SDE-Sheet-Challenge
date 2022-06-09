#include<bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int, bool> umap;
    for (int i=0 ; i<n ; i++){
        umap[a1[i]] = true;
    }
    for (int i=0 ; i<m ; i++){
        if (umap.count(a2[i]) > 0){
            continue;
        }
        return "No";
    }
    return "Yes";
}

int main(){

}