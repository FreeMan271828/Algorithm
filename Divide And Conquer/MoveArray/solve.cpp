#include<bits/stdc++.h>
using namespace std;

//将数组从begin到end翻转
void reverse(vector<char>&arr,int begin,int end){
    int size = end - begin +1;
    for(int i=0;i<size/2;i++){
        swap(arr[i+begin],arr[end-i]);
    }
}
//三步翻转
void solve(vector<char>&arr,int len){
    len %= arr.size();
    reverse(arr,0,len-1);
    reverse(arr,len,arr.size()-1);
    reverse(arr,0,arr.size()-1);
}

int main(){
    string str = "abcdefgh";
    vector<char>arr;
    arr.resize(str.length());
    arr.assign(str.begin(),str.end());
    solve(arr,3);
    for(auto elm : arr){
        cout<<elm;
    }

}