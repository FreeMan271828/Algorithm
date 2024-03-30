// The code will use Divide and Conqure to solve it.
#include <bits/stdc++.h>
using namespace std;
#define max 1025

int ChessBord[max][max];
int tile = 0;
void place(int tr, int tc, int dr, int dc, int size)
{
    if (size == 1)
        return;
    int t = ++tile;
    int s = size / 2;
    // 左上角
    if (dr < tr + s && dc < tc + s)
    {
        // 有特殊方块
        place(tr, tc, dr, dc, s);
    }
    else
    {
        // 没有特殊方块
        // 把骨牌的一块当做特殊方块，放置
        ChessBord[tr + s - 1][tc + s - 1] = t;
        place(tr, tc, tr + s - 1, tc + s - 1, s);
    }
    // 左下角
    if (dr >= tr + s && dc < tc + s)
    {
        place(tr + s, tc, dr, dc, s);
    }
    else
    {
        ChessBord[tr + s][tc + s - 1] = t;
        place(tr + s, tc, tr + s, tc + s - 1, s);
    }
    // 右上角
    if (dr < tr + s && dc >= tc + s)
    {
        place(tr, tc + s, dr, dc, s);
    }
    else
    {
        ChessBord[tr + s - 1][tc + s] = t;
        place(tr, tc + s, tr + s - 1, tc + s, s);
    }
    // 右下角
    if (dr >= tr + s && dc >= tc + s)
    {
        place(tr + s, tc + s, dr, dc, s);
    }
    else
    {
        ChessBord[tr + s][tc + s] = t;
        place(tr + s, tc + s, tr + s, tc + s, s);
    }
}

void print(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << ChessBord[i][j]<<'\t';
        }
        cout << '\n';
    }
}

int main()
{
    int k = 3;
    int sx = 1,sy = 2;
    int size = 1 << k;
    place(0, 0, sx, sy, size);
    print(size);
}