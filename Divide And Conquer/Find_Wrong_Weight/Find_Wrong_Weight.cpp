#include<bits/stdc++.h>
using namespace std;
/**
 *采用二分法
*/
int getSum(vector<int>vec,int begin,int end){
    int ans=0;
    for(int i=begin;i<end;i++){
        ans += vec[i];
    }
    return ans;
}

void solve(vector<int>vec,int begin,int end,int k){
    
}

int main(){
    int k = 8;
    vector<int>vec={k,k,3,k};
    solve(vec,0,4,k);
}