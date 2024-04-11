//采用一维优化算法
#include<bits/stdc++.h>
using namespace std;
void test(){
    int num, v;//输入物品数量和背包体积
    cin>>num>>v;
    vector<int>weight(num+1,0);//每一个物品的体积
    vector<int>value(num+1,0);//每一个物品的价值
    for(int i=1;i<=num ;i++){
        cin>>weight[i]>>value[i];
    }

    int dp[v+1]={0};
    for(int i=1;i<=num;i++){
        for(int j=v;j>=1;j--){
            if(j-weight[i]<0){
                dp[j] = dp[j];
            }else{
                dp[j] = max (dp[j],dp[j-weight[i]]+value[i]);
            }        
        }
    }
    cout<<dp[v]<<'\n';
}

int main(){
    test();
}