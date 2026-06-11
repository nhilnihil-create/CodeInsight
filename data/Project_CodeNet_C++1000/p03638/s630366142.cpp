#include<iostream>
#include<algorithm>
using namespace std;
int a[110][110] = {0};
int h, w, n, num = 1;
int color[10010];
//bool mark[110][110] = {0};
int go[][2] = {
    1,0,
    -1,0,
    0,1,
    0,-1
};
int what_color(int num)
{
    int i = 1;
    while(num - color[i] > 0)
    {
        num -= color[i];
        i++;
    }
    return i;
}
void dfs(int x, int y)
{
    if(num == h*w)
        return;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + go[i][0];
        int ny = y + go[i][1];
        if(nx < 1 || nx > h || ny < 1 || ny > w)
            continue;
        if(a[nx][ny] != 0)
            continue;
        a[nx][ny] = what_color(num);
        num++;
        dfs(nx, ny);
        if(num == h*w)
            return;
        num--;
        a[nx][ny] = 0;
    }
}
int main()
{
    cin >> h >> w >> n;
    for(int i = 1; i <= n; i++)
        cin >> color[i];
    a[1][1] = 1;
    color[1]--;
    dfs(1,1);
    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            if(j != 1)
                cout << ' ';
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}
