//#include <cstdio>
#include <iomanip>    // setw 控制输出间隔函数
#include <iostream>   // cin, cout, abs
#include <algorithm>  // max, min, swap, sort
#include <cmath>      // pow
#include <cstring>    // strlen
#include <set>        // set 集合
#include <stack>      // stack 栈
#include <queue>      // queue 队列
#include <string>     // string 字(yang)符(rou)串, substr
#include <map>
#include <fstream>
using namespace std;
int main()
{
    //freopen("aaa.in", "r", stdin);
    //freopen("aaa.out", "w", stdout);
    string h;
    cin >> h;
    string f = h;
    for( int i = 0; i < h.size(); i++)
        h[i] = f[h.size() - i - 1];
    for( int i = 0; i < h.size(); i++)
    {
        if( h[i] == 'b') h[i] = 'd';
        else if( h[i] == 'd') h[i] = 'b';
        else if( h[i] == 'p') h[i] = 'q';
        else if( h[i] == 'q') h[i] = 'p';
    }
    if( h == f) printf("Yes\n");
    else printf("No\n");
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
