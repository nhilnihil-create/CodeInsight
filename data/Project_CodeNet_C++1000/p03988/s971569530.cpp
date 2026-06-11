#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
int n,s,x,a[100];
bool c;
int main(){
    scanf("%d",&n);
    rep(i,n){ scanf("%d",&x); a[x]++; s = max(s, x); }
    rep(i,s+1){
        if(i < (s+1)/2){ if(a[i]) c = 1; }
        else if(i == (s+1)/2 && s%2){ if(a[i]-2) c = 1; }
        else if(i == (s+1)/2){ if(a[i]-1) c = 1; }
        else { if(a[i] < 2) c = 1; }
    }
    cout << (c ? "Impossible" : "Possible") << endl;
}