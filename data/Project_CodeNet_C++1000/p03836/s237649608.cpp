#include<bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define mod 998244353
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define REP(i,a,b) for(int i=a;i<b;i++)
#define maxx 200002
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main(){
    FASTIO
    int sx,sy,tx,ty;
    string s;
    cin>>sx>>sy>>tx>>ty;
    REP(i,0,ty-sy) s+='U';
    REP(i,0,tx-sx) s+='R';
    REP(i,0,ty-sy) s+='D';
    REP(i,0,tx-sx) s+='L';
    s+='L';
    REP(i,0,ty-sy+1) s+='U';
    REP(i,0,tx-sx+1) s+='R';
    s+='D';s+='R';
    REP(i,0,ty-sy+1) s+='D';
    REP(i,0,tx-sx+1) s+='L';
    s+='U';
    cout<<s<<endl;
    return 0;
}
