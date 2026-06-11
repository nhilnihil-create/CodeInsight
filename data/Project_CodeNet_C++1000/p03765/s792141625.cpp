#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

char str[2][N];
int s[2][N], q;

int main(){
    cin >> str[0] + 1 >> str[1] + 1;
    for (int type = 0; type < 2; type++)
        for (int i = 1; i <= strlen(str[type] + 1); i++)
            s[type][i] = s[type][i - 1] + (str[type][i] != 'A') + 1;
    cin >> q;
    while (q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        puts(((s[0][b] - s[0][a - 1]) - (s[1][d] - s[1][c - 1])) % 3 == 0 ? "YES" : "NO");
    }
}
