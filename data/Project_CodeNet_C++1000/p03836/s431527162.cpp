#include<bits/stdc++.h>
using namespace std;
#define INFTY 1<<20
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long int ll;
const int MOD=1000000007;

int main(){
    int sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    int dx = tx-sx,dy = ty-sy;
    string s;
    s += 'L';
    rep(i,dy+1)s += 'U';
    rep(i,dx+1)s += 'R';
    s += 'D';
    
    rep(i,dx)s += 'L';
    rep(i,dy)s += 'D';

    s+= 'D';
    rep(i,dx+1)s += 'R';
    rep(i,dy+1)s += 'U';
    s += 'L';

    rep(i,dy)s += 'D';
    rep(i,dx)s += 'L';

    cout<<s<<endl;
    return 0;
}