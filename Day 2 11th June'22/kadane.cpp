//Kadane's algo / maximum subarray sum
#include<bits/stdc++.h>
using namespace std;

//brute force -> O(n^2)
int maxSubarraySum(vector<int> arr){
    int max_sum = INT_MIN;
    for (int i=0 ; i<arr.size() ; i++){
        int curr_sum = 0;
        for (int j=i ; j<arr.size() ; j++){
            curr_sum += arr[j];
            if (curr_sum > max_sum){
                max_sum = curr_sum;
            }
        }
    }
    return max_sum;
}

//optimized sol -> o(n) -> Kadane's Algo
int maxSubarrySumKadane(vector<int> &arr){
    int sum = 0;
    int maxi = INT_MIN;
    for (auto x : arr){
        sum += x;
        maxi = max(sum, maxi);
        if (sum < 0) sum = 0;
    }
    return maxi;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0 ; i<n ; i++){
        cin >> arr[i];
    }

    cout << maxSubarrySumKadane(arr);
}