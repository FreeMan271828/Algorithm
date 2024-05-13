/*
*该代码是朴素二维数组解决01背包
*/
#include<bits/stdc++.h>
using namespace std;

void getDp(vector<int>&weight,vector<int>&value,vector<vector<int>>&dp,int num,int v);
vector<int> trackBack(vector<vector<int>>&dp,vector<int>weight,int num,int v);

void solve(){
    int num, v;//输入物品数量和背包体积
    cin>>num>>v;
    vector<int>weight(num+1);//每一个物品的体积
    vector<int>value(num+1);//每一个物品的价值
    weight[0] = value[0] = 0;
    for(int i=1;i<=num ;i++){
        cin>>weight[i]>>value[i];
    }
    //dp[i][j]为前i个物品，前j个容量下的存储价值最大
    vector<vector<int>>dp(num+1,vector<int>(v+1,0));
    getDp(weight,value,dp,num,v);
    cout<<"The max is"<<'\n';
    cout<<dp[num][v]<<'\n';
    trackBack(dp,weight,num,v);
}

int main(){
    solve();
}

void getDp(vector<int>&weight,vector<int>&value,vector<vector<int>>&dp,int num,int v){
    for(int i=1;i<=num;i++){
        for(int j=1;j<=v;j++){
            if(j-weight[i]<0){
                dp[i][j] = dp[i-1][j];
                continue;
            }
            dp[i][j] = max( dp[i-1][j], dp[i-1][j-weight[i]]+value[i] );
        }
    }
}

vector<int>trackBack(vector<vector<int>>&dp,vector<int>weight,int num,int v){
    vector<int>objectIndex;
    int row = num;
    int col = v;
    while(row>0&&col>0){
        if(dp[row-1][col]!=dp[row][col]){
            objectIndex.push_back(row);
            row--;
            col-=weight[row];
        }
        else{
            row--;
        }
    }
    vector<int>::reverse_iterator rit;
    cout<<"The object index is"<<'\n';
    for(rit = objectIndex.rbegin();rit<objectIndex.rend();rit++){
        cout<<*rit<<' ';
    }
    return objectIndex;
}