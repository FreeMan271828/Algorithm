#include<bits/stdc++.h>
using namespace std;

int ans = 0;
void merge(vector<int>&arr,int begin,int mid,int end){
    vector<int>temp;
    int left = 0,right=mid+1;
    while(left<=mid&&right<=end){
        if(arr[left]<arr[right]){
            temp.push_back(arr[left++]);
        }
        else{
            temp.push_back(arr[right++]);
            ans+=mid-left+1;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left++]);
    }
    while(right<=end){
        temp.push_back(arr[right++]);
    }
    arr=temp;
}
void solve(vector<int>&arr,int begin,int end){
    if(begin<end){
        int n = (begin+end)/2;
        solve(arr,begin,n);
        solve(arr,n+1,end);
        merge(arr,begin,n,end);
    }
}

int main(){
    vector<int>arr={2,3,1};
    solve(arr,0,arr.size()-1);
    cout<<ans;
}