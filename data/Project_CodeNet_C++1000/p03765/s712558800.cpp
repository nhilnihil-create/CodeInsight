#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
    string s, t;
    cin >> s >> t;
    int n=s.length(), m=t.length();
    int d1[n+1], d2[m+1];
    d1[0]=0, d2[0]=0;
    for(int i=0; i<n; i++){
        if(s[i]=='A') d1[i+1]=d1[i]+1;
        else d1[i+1]=d1[i]+2;
        d1[i+1]%=3;
    }
    for(int i=0; i<m; i++){
        if(t[i]=='A') d2[i+1]=d2[i]+1;
        else d2[i+1]=d2[i]+2;
        d2[i+1]%=3;
    }

    int q;
    cin >> q;
    for(int i=0; i<q; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if((d1[b]-d1[a-1]+3)%3==(d2[d]-d2[c-1]+3)%3) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}