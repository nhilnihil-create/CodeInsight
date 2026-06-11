#include <bits/stdc++.h>
using namespace std;

int n, m, d;
string s = "RYGB";

int main()
{
    cin >> n >> m >> d;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int x = i+j+m, y = i-j+m;
            putchar(s[((x/d)&1)*2 + ((y/d)&1)]);
        }
        putchar('\n');
    }

    return 0;
}