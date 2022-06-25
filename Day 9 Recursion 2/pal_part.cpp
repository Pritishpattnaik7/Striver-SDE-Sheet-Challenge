#include<bits/stdc++.h>
using namespace std;

bool isPal(string s, int start, int end){
    while (start <= end){
        if (s[start++] != s[end--]){
            return false;
        }
    }
    return true;
}

void helper(int ind, string s, vector<string> &ds, vector<vector<string>> &ans){
    //base cond
    if (ind == s.size()){
        ans.push_back(ds);
        return;
    }
    
    for (int i=ind ; i<s.size() ; i++){
        if (isPal(s, ind, i)){
            ds.push_back(s.substr(ind, i-ind+1));
            helper(i+1, s, ds, ans);
            ds.pop_back();  //backtrack
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> ds;
    helper(0, s, ds, ans);
    return ans;
}

int main(){
}