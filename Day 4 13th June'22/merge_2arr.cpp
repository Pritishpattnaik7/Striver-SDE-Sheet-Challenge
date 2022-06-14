#include<bits/stdc++.h>
using namespace std;

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    vector<int> arr3(m+n, 0);
    int i=0, j=0, k=0;
    
    while (i<m and j<n){
        if (arr1[i] <= arr2[j]){
            arr3[k++] = arr1[i++];
        }
        else {
            arr3[k++] = arr2[j++];
        }
    }
    while (i<m){
        arr3[k++] = arr1[i++];
    }
    while (j<n){
        arr3[k++] = arr2[j++];
    }
    
    return arr3;
}

//optimized o(1) space 
void merge2SortedArrays(vector<int> arr1, vector<int> arr2, int n, int m){
    int i, k;
    for (i=0 ; i<n ; i++){
        if (arr1[i] > arr2[0]){
            swap(arr1[i], arr2[0]);
        }

        //then sort the arr2 by insertion sort
        int key = arr2[0];
        for (k=1 ; k<m and arr2[k] < key ; k++){
            arr2[k-1] = arr2[k];
        }
        arr2[k-1] = key;
    }
}

int main(){
}