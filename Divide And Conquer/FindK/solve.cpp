#include<bits/stdc++.h>
using namespace std;

//将第一个数排好，并且返回其序列
int partition(vector<int>&vec,int begin,int end){
    int left = begin;
    int right = end;
    int temp = vec[begin];
    while(left<right){
        //寻找到第一个小于基准的数
        while(left<right && vec[right]>=temp){
            right--;
        }
        //寻找到第一个大于基准的数
        while (left<right && vec[left]<=temp){
            left++;
        }
        swap(vec[left],vec[right]);
    }
    swap(vec[begin],vec[left]);
    return left;
}

int solve(vector<int>vec,int k,int begin,int end){
    int polit = partition(vec,begin,end);
    if(polit == k){
        cout<<vec[polit];
        return vec[polit];
    }
    else if(polit<k){
        return solve(vec,k,polit+1,end);
    }
    else{
        return solve(vec,k,0,polit-1);
    }
}

int main(){
    vector<int>vec={2,6,1,3,7};
    int ans = solve(vec,3,0,vec.size()-1);
    cout<<ans;
}   