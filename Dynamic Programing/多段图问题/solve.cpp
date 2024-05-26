//
// Created by FreeMan on 2024/5/24.
//

#include "solve.h"

int main(){
    DP();
}

void DP(){
    int total = 7;
    vector<vector<int>>courses(5,vector<int>(5,0));
    vector<vector<int>>scores(5,vector<int>(total+1,0));

    courses[1]={0,4,4,5,8};
    courses[2]={0,3,5,6,7};
    courses[3]={0,5,6,8,8};
    courses[4]={0,2,4,7,8};

    for(int i=1;i<=4;i++){
        for(int j=1;j<=total;j++){
            //scores[i][j]代表前i个课程分配j天
            for(int k=1;k<=4;k++){
                int temp;
                if(j-k <0 ){
                    continue;
                }
                scores[i][j] = max(scores[i-1][j-k]+courses[i][k],scores[i][j]);
            }
        }
    }
    cout<<scores[4][7];
    backtrack(total,scores,courses);
}

void backtrack(int totalDays,vector<vector<int>>&scores,vector<vector<int>>&courses) {
    int i = 4, j = totalDays;
    vector<int> daysAssigned(5, 0);
    while (i > 0) {
        for (int k = 4; k >= 1; k--) { // 从4天开始逆向检查
            if (scores[i][j] == scores[i - 1][j - k] + courses[i][k]) {
                daysAssigned[i - 1] = k; // 找到分配天数
                j -= k; // 更新剩余天数
                break; // 跳出循环
            }
        }
        i--;
    }
    for(int i=0;i<4;i++){
        cout<<'\n'<<daysAssigned[i]<<'\t';
    }
}
