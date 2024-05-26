# 移动数组

将一个数组向左循环移动n位。

## 思路

可以将数组Arr分成两个部分：X(前n位)Y。最后要实现的就是变成YX。
可以YX = ( (X)^T (Y)^T )^T。
所以可以采用三步翻转法：
Reverse(arr,begin,n);
Reverse(arr,n+1,end);
Reverse(arr,begin,end);
