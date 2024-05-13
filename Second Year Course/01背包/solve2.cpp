/*
*采用一维优化算法
*dp[i]代表背包体积为i时取得的最大价值
*/
#include<bits/stdc++.h>
using namespace std;

void print(vector<int>&value);
void getDp(vector<int>&weight,vector<int>&value,vector<int>&dp,int num,int v);

void solve(){
    int num, v;//输入物品数量和背包体积
    cin>>num>>v;
    vector<int>weight(num+1,0);//每一个物品的体积
    vector<int>value(num+1,0);//每一个物品的价值
    for(int i=1;i<=num ;i++){
        cin>>weight[i]>>value[i];
    }
    vector<int>dp(v+1,0);
    getDp(weight,value,dp,num,v);
    cout<<dp[v]<<'\n';
}

int main(){
    solve();
}

void print(vector<int> &value){
    for(auto elm : value){
        cout<<elm <<' ';
    }
    cout<<'\n';
}

void getDp(vector<int> &weight, vector<int> &value, vector<int> &dp, int num, int v)
{
    for(int i=1;i<=num;i++){
        for(int j=v;j>=1;j--){
            if(j-weight[i]<0){
                dp[j] = dp[j];
            }else{
                dp[j] = max (dp[j],dp[j-weight[i]]+value[i]);
            }
            print(dp);
        }
    }
}