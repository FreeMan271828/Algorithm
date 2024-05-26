//
// Created by FreeMan on 24-5-26.
//
#include <bits/stdc++.h>
using namespace std;

class task{
public:
    int id;
    int time_m1;
    int time_m2;
};
bool cmp1(task task1,task task2);
bool cmp2(task task1,task task2);

void DivideAndSort(vector<task>&vec){
    int flag=-1;//表示前[0--flag]是第1组，之后是第二组
    for(int i=0;i<vec.size();i++){
        if(vec[i].time_m1<vec[i].time_m2){
            flag ++;
            swap(vec[i],vec[flag]);
        }
    }
    sort(vec.begin(),vec.begin()+flag+1, cmp1);
    sort(vec.begin()+flag+1,vec.end(),cmp2);

    int f1=vec[0].time_m1,f2=vec[0].time_m2;
    cout<<"best method: ";
    cout<<vec[0].id<<' ';
    for(auto it = vec.begin()+1;it<vec.end();it++){
        cout<<(*it).id<<' ';
        f1+=(*it).time_m1;
        f2=max(f1,f2)+(*it).time_m2;
    }
    cout<<'\n'<<"best time: "<<f2<<'\n';
}

int main(){
    int num = 4;//作业数
    vector<task>vec(num);
    vec[0].id=1;    vec[0].time_m1=5;   vec[0].time_m2=6;
    vec[1].id=2;    vec[1].time_m1=12;  vec[1].time_m2=2;
    vec[2].id=3;    vec[2].time_m1=4;   vec[2].time_m2=14;
    vec[3].id=4;    vec[3].time_m1=8;   vec[3].time_m2=7;
    DivideAndSort(vec);
}

bool cmp1(task task1,task task2){
    return task1.time_m1<task2.time_m1;//按照m1从小到大排序
}

bool cmp2(task task1,task task2){
    return task1.time_m2>task2.time_m2;//按照m2从大到小排序
}