#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int,int>;
int main(void) {
    string a, b, c; 
    cin >> a >> b >> c;
    a[0] = 'A'+a[0]-'a';
    b[0] = 'A'+b[0]-'a';
    c[0] = 'A'+c[0]-'a';
    cout << a[0] << b[0] << c[0];
}
