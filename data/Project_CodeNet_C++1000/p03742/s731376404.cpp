#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int solve(int x, int y)
{
    for (int i = 1; 2*i <= x; ++i){
        if (!solve(x-2*i, y)) return 1;
    }
    for (int i = 1; 2*i <= y; ++i){
        if (!solve(x, y-2*i)) return 1;
    }
    return 0;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(0);
//    for (int i = 1; i <= 50; ++i){
//        for (int j = 1; j <= 50; ++j){
//            printf("x %d y %d ", i, j);
//            if (solve(i, j)) cout << "Alice" << endl;
//            else cout << "Brown" << endl;
//        }
//    }
    long long x, y;
    cin >> x >> y;
    if (abs(x-y) == 0 || abs(x-y) == 1) cout << "Brown" << endl;
    else cout << "Alice" << endl;
    return 0;
}
