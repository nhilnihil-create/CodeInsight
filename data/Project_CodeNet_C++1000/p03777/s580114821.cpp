#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    char a, b;
    cin >> a >> b;
    if(a == 'H' && b == 'H') cout << 'H';
    if(a == 'H' && b == 'D') cout << 'D';
    if(a == 'D' && b == 'H') cout << 'D';
    if(a == 'D' && b == 'D') cout << 'H';
    return 0;
}