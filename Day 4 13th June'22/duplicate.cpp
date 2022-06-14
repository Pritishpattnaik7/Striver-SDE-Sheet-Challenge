#include <bits/stdc++.h>
using namespace std;

// using maps
int findDuplicate(vector<int> &nums)
{
    map<int, int> mp;
    for (auto x : nums)
    {
        mp[x]++;
    }

    int ans;
    for (auto it : mp)
    {
        if (it.second > 1)
        {
            return it.first;
        }
    }
    return 0;
}

//linked list slow and fast pointer approach => o(1) space and o(n) time
int findDuplicateOpt(vector<int> &nums){
    int slow = nums[0];
    int fast = nums[0];
    
    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    while (slow != fast);

    fast = nums[0];
    while (slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0 ; i<n ; i++){
        cin >> nums[i];
    }

    cout << findDuplicate(nums) << endl;
    cout << findDuplicateOpt(nums) << endl;
}