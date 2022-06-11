#include<bits/stdc++.h>
using namespace std;

//leetcode , my approach
void sortColors(vector<int>& nums) {
        vector<int> zeroes, ones, twos;
        for (auto x : nums){
            if (x == 0) zeroes.push_back(x);
            else if (x == 1) ones.push_back(x);
            else if (x == 2) twos.push_back(x);
        }
        nums.clear();
        for (int i=0 ; i<zeroes.size() ; i++){
            nums.push_back(zeroes[i]);
        }
        for (int i=0 ; i<ones.size() ; i++){
            nums.push_back(ones[i]);
        }
        for (int i=0 ; i<twos.size() ; i++){
            nums.push_back(twos[i]);
        }
}

//dutch national flag algo
//optimized sol -> o(n) t.c and o(1) s.c
void sortColorsOpt(vector<int> &nums){
    int lo = 0;
    int hi = nums.size()-1;
    int mid = 0;

    while (mid <= hi){
        switch (nums[mid])
        {
        case 0:
            swap(nums[lo++], nums[mid++]);
            break;

        case 1:
            mid++;
            break;    
        
        case 2:
            swap(nums[mid], nums[hi--]);
            break;
        }
    }
}

int main(){
}