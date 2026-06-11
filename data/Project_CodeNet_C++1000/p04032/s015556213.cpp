#include <bits/stdc++.h>
using namespace std;
 
#define oo 1e9
#define fi first
#define se second
#define sp(iiii) setprecision(iiii)
#define IO ios_base::sync_with_stdio(false); cin.tie(0)
#define ms(aaaa,xxxx) memset(aaaa,xxxx,sizeof(aaaa))
#define cntbit(xxxx) __builtin_popcount(xxxx)
#define getbit(xxxx,aaaa) ((xxxx>>(aaaa-1))&1)
#define _cos(xxxx) cos(xxxx*acos(-1)/180)
#define _sin(xxxx) sin(xxxx*acos(-1)/180)
#define _tan(xxxx) tan(xxxx*acos(-1)/180)
#define PE cout<<fixed
#define sqr(x) ((x)*(x))
 
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
typedef pair<long long,long long> pll;
typedef pair<pair<long long,long long>,long long> plll;
 
const ld pi=acos(-1);

ll l,r,i,sl[509];
string s;

bool ok() {
    for (int ii='a';ii<='z';ii++) {
        if (sl[ii]>=2) {
            return true;
        }
    }
    return false;
}

int main() {
    IO;
    cin>>s;
    if (s.length()==2) {
        if (s[0]==s[1]) {
            cout<<1<<' '<<2<<'\n';
        }
        else {
            cout<<"-1 -1\n";
        }
    }
    else {
        l=-1;
        r=-1;
        sl[s[0]]++;
        sl[s[1]]++;
        sl[s[2]]++;
        if (ok()) {
            l=1;
            r=3;
        }
        for (i=3;i<s.length();i++) {
            sl[s[i-3]]--;
            sl[s[i]]++;
            if (ok()) {
                l=i-1;
                r=i+1;
            }
        }
        cout<<l<<' '<<r<<'\n';
    }
}
    