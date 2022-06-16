#include<bits/stdc++.h>
using namespace std;

//hashmap approach
vector<int> majorityElement(vector<int>& nums) {
        map<int, int> mp;
        vector<int> ans;
        for (auto x : nums){
            mp[x]++;
        }
        
        for (auto it : mp){
            if (it.second > nums.size()/3){
                ans.push_back(it.first);
            }
        }
        return ans;
}

//bayer moore voting algo
vector<int> majorityElementOpt(vector<int> &nums){
}

int main(){
}