#include<bits/stdc++.h>
using namespace std;
/*
*分析（设田忌最快的马为h1,最慢的马为h2；齐威王最快的马为H1,最慢的马为H2）
*1. if h1>H1, h1 <-> H1 +200
*2. if h1<H1, h2 <-> H1 -200
*3. if h1=H1
*   1.if h2>H2, h2 <-> H2 +200
*   2.if h2<H2 and h2 < H1, h2 <-> H1 -200
*   3.else null 0
*/
class Houses{
private:
    vector<int>vec;
    int left;
    int right;
public:
    Houses(){}
    Houses(vector<int>data){
        sort(data.begin(),data.end());
        this->vec = data;
        left=0;
        right=data.size()-1;
    }
    bool isEmpty(){return left>right;}
    void useFast(){right--;}
    void useSlow(){left++;}
    int getFast(){return vec[right];}
    int getSlow(){return vec[left];}
};

void greedy(Houses* houses1,Houses* houses2);

void solve(){
    int n;
    cin>>n;
    //田忌的马
    vector<int>data1(n,0);
    //齐威王的马
    vector<int>data2(n,0);
    for(int i=0;i<n;i++){
        cin>>data1[i];
    }
    for(int i=0;i<n;i++){
        cin>>data2[i];
    }
    Houses* houses1 = new Houses(data1);
    Houses* houses2 = new Houses(data2);
    greedy(houses1,houses2);
}

int main(){
    solve();
}

/*
*houses1为田忌的马
*houses2为齐威王的马
*/
void greedy(Houses* houses1,Houses* houses2){
    int ans = 0;
    while(!houses1->isEmpty()||!houses2->isEmpty()){
        if(houses1->getFast()>houses2->getFast()){
            houses1->useFast();
            houses2->useFast();
            ans+=200;
        }
        else if(houses1->getFast()<houses2->getFast()){
            houses1->useSlow();
            houses2->useFast();
            ans-=200;
        }
        else{
            if(houses1->getSlow()>houses2->getSlow()){
                houses1->useSlow();
                houses2->useSlow();
                ans+=200;
            }
            else if(houses1->getSlow()<houses2->getSlow()){
                ans-=200;
                houses1->useSlow();
                houses2->useFast();
            }
            else{
                houses1->useFast();
                houses1->useSlow();
                houses2->useFast();
                houses2->useSlow();
            }
        }
    }
    cout<<ans;
}