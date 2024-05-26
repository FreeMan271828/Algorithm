#include<bits/stdc++.h>
using namespace std;

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

void quickSort(vector<int>&vec,int begin,int end){
    if(begin>=end){
        return;
    }
    int pilot = partition(vec,begin,end);
    quickSort(vec,begin,pilot-1);
    quickSort(vec,pilot+1,end);
}

int main(){
    vector<int>vec={2,5,1,7};
    quickSort(vec,0,vec.size()-1);
    for(auto elm : vec){
        cout<<elm;
    }
}