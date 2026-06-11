#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pil = pair<pii,int>;


int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int s,t;
    s = max(a,c);
    t = min(b,d);
    if(t-s < 0)cout << 0 << endl;
    else cout << t-s << endl;
}