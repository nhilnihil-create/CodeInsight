#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    int a,b;
    cin >> a >> b;
    if(a == 1)a = 14;
    if(b == 1)b = 14;
    if(a < b)cout << "Bob" << endl;
    if(a == b)cout << "Draw" << endl;
    if(a > b)cout << "Alice" << endl;
}