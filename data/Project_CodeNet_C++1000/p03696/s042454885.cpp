#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001
//0=48,A=65,a=97

int main() {
    int n;string s;
    cin >> n >> s;
    int x=0;
    int d=0,a;
    for(int i = 0; i < n; i++) {
        if(s[i]=='(') d++;
        else d--;
        x=min(x,d);
    }

    for(int i = 0; i < -x; i++) {
        cout << '(';
    }
    cout << s;

    for(int i = 0; i < d-x; i++) {
        cout << ')';
    }

    cout << endl;

    return 0;
}