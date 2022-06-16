#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums){
    if (nums.size() == 0){
        return 0;
    }

    sort(nums.begin(), nums.end());

    int ans = 1;
    int prev = nums[0];
    int cur = 1;

    for (int i=1 ; i<nums.size() ; i++){
        if (nums[i] == prev + 1){
            cur++;
        }
        else if (nums[i] != prev){
            cur = 1;
        }
        prev = nums[i];
        ans = max(ans, cur);
    }
    return ans;
}

//optimized approach => tc - o(n), space - o(n)
int longestConsecutiveOpt(vector<int> &nums){
    set<int> hashSet;
    for (auto x : nums){
        hashSet.insert(x);
    }

    int longestStreak = 0;

    for (auto x : nums){
        if (hashSet.find(x-1) == hashSet.end()){
            int currNum = x;
            int currStreak = 1;

            while (hashSet.find(currNum + 1) != hashSet.end()){
                currNum++;
                currStreak++;
            }
             longestStreak = max(longestStreak, currStreak);
        }
    }
    return longestStreak;
} 

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0 ; i<n ; i++){
        cin >> nums[i];
    }

    int ans = longestConsecutiveOpt(nums);
    cout << ans;
}