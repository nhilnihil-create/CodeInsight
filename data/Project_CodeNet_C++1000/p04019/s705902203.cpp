#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin>>s;
    int n = s.size(),N=0,E=0,W=0,S=0;
    for(int i=0; i<n; i++) {
        if(s[i] == 'N') N++;
        if(s[i] == 'E') E++;
        if(s[i] == 'W') W++;
        if(s[i] == 'S') S++;
    }
    if(N==0 && S==0 && E>0 && W>0) {
        cout<<"Yes";
    }
    else if(E==0 && W==0 && N>0 && S>0) {
        cout<<"Yes";
    }
    else if(N>0 && E>0 && W>0 && S>0) {
        cout<<"Yes";
    }
    else cout<<"No";
}