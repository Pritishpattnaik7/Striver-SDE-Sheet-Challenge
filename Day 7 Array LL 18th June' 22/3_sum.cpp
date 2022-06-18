#include<bits/stdc++.h>
using namespace std;

//brute force => o(n^3)
vector<vector<int>> threeSum(vector<int> &nums){
    set<vector<int>> hshSet;
    for (int i=0 ; i<nums.size() ; i++){
        for (int j=i+1 ; j<nums.size() ; j++){
            for (int k=j+1 ; k<nums.size() ; k++){
                if (nums[i] + nums[j] + nums[k] == 0){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    sort(temp.begin(), temp.end());
                    hshSet.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans;
    for (auto it : hshSet){
        ans.push_back(it);
    }
    return ans;
}

//optimized sol
vector<vector<int>> threeSumOpt(vector<int> &nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;

    for (int i=0 ; i<nums.size()-2 ; i++){
        if (i == 0 or (i > 0 and nums[i] != nums[i-1])){
            int lo = i+1, hi = nums.size()-1;
            int sum = 0 - nums[i];
            while (lo < hi){
                if (nums[lo] + nums[hi] == sum){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[lo]);
                    temp.push_back(nums[hi]);
                    res.push_back(temp);

                    while (lo < hi and nums[lo] == nums[lo+1]) lo++;
                    while (lo < hi and nums[hi] == nums[hi-1]) hi--;

                    lo++;
                    hi--;
                }
                else if (nums[lo] + nums[hi] < sum) lo++;
                else hi--;
            }
        }
    }
    return res;
}


int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0 ; i<n ; i++){
        cin >> nums[i];
    }

    vector<vector<int>> ans = threeSumOpt(nums);
    for (int i=0 ; i<ans.size() ; i++){
        for (int j=0 ; j<ans[0].size() ; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}