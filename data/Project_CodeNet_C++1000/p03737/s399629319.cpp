#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    string a, b, c;
    cin >> a >> b >> c;
    char dif = 'A' - 'a';
    printf("%c%c%c\n", a[0] + dif, b[0] + dif, c[0] + dif);
    return 0;
}