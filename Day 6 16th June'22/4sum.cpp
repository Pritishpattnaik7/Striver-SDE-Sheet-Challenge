#include<bits/stdc++.h>
using namespace std;

//brute force approach => O(n^3)
void fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    set<vector<int>> sv;
    for (int i=0 ; i<n ; i++){
        for (int j=i+1 ; j<n ; j++){
            for (int k=j+1 ; k<n ; k++){
                int x = target - (nums[i] + nums[j] + nums[k]);
                if (binary_search(nums.begin()+k+1 , nums.end(), x)){
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    v.push_back(x);
                    sort(v.begin(), v.end());
                    sv.insert(v);
                }
            }
        }
    }

    for (auto x : sv){
        vector<int> temp = x;
        for (auto z : temp){
            cout << z << " ";
        }
        cout << endl;
    }
}

//approach 2 => eliminating the hashset
vector<vector<int>> fourSumOpt(vector<int> &nums, int target){
    vector<vector<int>> res;
    if (nums.size() == 0) return res;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for (int i=0 ; i<n ; i++){
        for (int j=i+1 ; j<n ; j++){
            int target2 = target - (nums[i] + nums[j]);
            int left = j+1;
            int right = n - 1;

            while (left < right){
                int two_sum = nums[left] + nums[right];
                if (two_sum < target2) left++;
                else if (two_sum > target2) right--;
                else {
                    vector<int> quadruplet(4, 0);
                    quadruplet[0] = nums[i];
                    quadruplet[1] = nums[j];
                    quadruplet[2] = nums[left];
                    quadruplet[3] = nums[right];
                    res.push_back(quadruplet);

                    //processing the duplicates of number 3
                    while (left < right and nums[left] == quadruplet[2]) ++left;

                    //processing the duplicates of number 4
                    while (left < right and nums[right] == quadruplet[3]) --right;
                }
            }
            //processing the duplicates for j
            while (j+1 < n and nums[j+1] == nums[j]) ++j;
        }
        //processing the duplicates for i
        while (i+1 < n and nums[i+1] == nums[i]) ++i;
    }
    return res;
}

//leetcode accepted solution
vector<vector<int>> fourSumLeetcode(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() == 0) return res;
        int n = nums.size();
        
        //sort the array
        sort(nums.begin(), nums.end());
        
        for (int i=0 ; i<n ; i++){
            long target3 = target - nums[i];
            for (int j=i+1 ; j<n ; j++){
                long target2 = target3 - nums[j];
                int left = j+1;
                int right = n-1;
                
                while (left < right) {
                    int two_sum = nums[left] + nums[right];
                    if (two_sum < target2) left++;
                    else if (two_sum > target2) right--;
                    else {
                        vector<int> v(4, 0);
                        v[0] = nums[i];
                        v[1] = nums[j];
                        v[2] = nums[left];
                        v[3] = nums[right];
                        res.push_back(v);
                    
                        while (left < right and nums[left] == v[2]) ++left;
                     
                        while (left < right and nums[right] == v[3]) --right;
                    }
                }
                while (j+1 < n and nums[j+1] == nums[j]) ++j;
            }
            while (i+1 < n and nums[i+1] == nums[i]) ++i;
        }
        return res;
    }

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
    int target;
    cin >> target;

    //fourSum(arr, target);
    vector<vector<int>> ans = fourSumOpt(arr, target);
    int n1 = ans.size();
    int m1 = ans[0].size();
    for (int i=0 ; i<n1 ; i++){
        for (int j=0 ; j<m1 ; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}