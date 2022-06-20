//trapping rainwater
#include<bits/stdc++.h>
using namespace std;

//brute force => o(N^2)
int trapBrute(vector<int>& height) {
    int n = height.size();
    int waterTrapped = 0;
    for (int i=0 ; i<n ; i++){
        int j = i;
        int leftMax = 0, rightMax = 0;
        while (j >= 0){
            leftMax = max(leftMax, height[j]);
            j--;
        }
        j = i;
        while (j < n){
            rightMax = max(rightMax, height[j]);
            j++;
        }

        waterTrapped += min(leftMax, rightMax) - height[i];
    }
    return waterTrapped;
}

//using a prefix and suffix array
int trapBetter(vector<int> &height){
    int n = height.size();

    //pre computation of suffix and prefix array
    vector<int> prefix(n), suffix(n);
    prefix[0] = height[0];
    for (int i=1 ; i<n ; i++){
        prefix[i] = max(prefix[i-1], height[i]);
    }
    suffix[n-1] = height[n-1];
    for (int i=n-2 ; i>=0 ; i--){
        suffix[i] = max(suffix[i+1], height[i]);
    }

    int waterTrapped = 0;
    for (int i=0 ; i<n ; i++){
        waterTrapped += min(prefix[i], suffix[i]) - height[i];
    }

    return waterTrapped;
}

//2 pointer approach Most optimized , tc->o(n) , sc->o(1)
int trapOpt(vector<int> &height){
    int n = height.size();
    int l = 0, r = n-1;
    int leftMax = 0, rightMax = 0, waterTrapped = 0;

    while (l <= r){
        if (height[l] <= height[r]){
            if (height[l] >= leftMax){
                leftMax = height[l];
            }
            else {
                waterTrapped += leftMax - height[l];
            }
            l++;
        }
        else {
            if (height[r] >= rightMax){
                rightMax = height[r];
            }
            else {
                waterTrapped += height[r];
            }
            r--;
        }
    }
    return waterTrapped;
}

int main(){
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i=0 ; i<n ; i++){
        cin >> height[i];
    }

    int ans = trapOpt(height);
    cout << ans << "\n";
}