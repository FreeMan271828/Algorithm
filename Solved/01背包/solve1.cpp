//该代码是朴素二维数组解决01背包
#include<bits/stdc++.h>
using namespace std;

void test(){
    int num, v;//输入物品数量和背包体积
    cin>>num>>v;
    vector<int>weight(num+1);//每一个物品的体积
    vector<int>value(num+1);//每一个物品的价值
    weight[0] = value[0] = 0;
    for(int i=1;i<=num ;i++){
        cin>>weight[i]>>value[i];
    }

    //dp[i][j]为前i个物品，前j个容量下的存储价值最大
    int dp[num+1][v+1];
    for(int i=0;i<=num;i++){
        dp[i][0] = 0;//背包体积为0一定为0
    }
    for(int i=0;i<=v;i++){
        dp[0][i] = 0;//没有物品一定为0
    }
    for(int i=1;i<=num;i++){
        for(int j=1;j<=v;j++){
            if(j-weight[i]<0){
                dp[i][j] = dp[i-1][j];
                continue;
            }
            dp[i][j] = max( dp[i-1][j], dp[i-1][j-weight[i]]+value[i] );
            cout<<"前"<<i<<"个物品, "<<"前"<<j<<"个容量可以包含的最大价值是"<<dp[i][j]<<'\n';
        }
    }
    cout<<dp[num][v]<<'\n';
}
int main(){
    test();
}