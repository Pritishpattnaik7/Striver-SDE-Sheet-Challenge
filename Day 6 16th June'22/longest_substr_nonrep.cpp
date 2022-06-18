//Length of Longest Substring without any Repeating Character
#include<bits/stdc++.h>
using namespace std;

//Brute force => o(n^2)
int lengthOfLongestSubstring(string str){
    int maxi = 0;
    for (int i=0 ; i<str.size() ; i++){
        unordered_set<int> s;
        for (int j=i ; j<str.size() ; j++){
            if (s.find(str[j]) != s.end()){
                maxi = max(maxi, j-i);
                break;
            }
            else {
                s.insert(str[j]);
            }
        }
    }
    return maxi;
}

//optimized approach 1 => o(2n)
int lengthOfLongestSubstringOpt1(string str){
    int max_len = 0;
    unordered_set<int> s;
    int l=0;
    for (int r=0 ; r<str.size() ; r++){
        if (s.find(str[r]) != s.end()){
            while (l < r and s.find(str[r]) != s.end()){
                s.erase(str[l]);
                l++;
            }
        }
        s.insert(str[r]);
        max_len = max(max_len, r-l+1);
    }
    return max_len;
}

int main(){
    string str;
    cin >> str;

    int ans = lengthOfLongestSubstringOpt1(str);
    cout << ans;
}