#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int m;
    m = max({a,b,c});
    cout << a+b+c-m << endl;
}