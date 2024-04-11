#include<bits/stdc++.h>
using namespace std;
int main(){
    int v,n;
    cin>>v>>n;
    vector<int>vec(n+1,0);//vec是每一个物体占的体积
    for(int i=1;i<=n;i++){
        cin>>vec[i];
    }
    
    int dp[v+1]={0};//当背包体积为v的时候可容纳的最大体积
    for(int i=1;i<=n;i++){
        for(int j=v;j>=vec[i];j--){
            if(dp[j-vec[i]]+vec[i]>=dp[j]){
                dp[j]=max(dp[j],dp[j-vec[i]]+vec[i]);
            }
        }
    }

    cout<<v-dp[v]<<'\n';
}