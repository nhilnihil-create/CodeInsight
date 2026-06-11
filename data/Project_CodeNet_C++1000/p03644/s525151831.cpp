#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;

int main(void){
    int n;
    cin>>n;
    if(n==1) cout<<1<<endl;
    else if(n<4) cout<<2<<endl;
    else if(n<8) cout<<4<<endl;
    else if(n<16) cout<<8<<endl;
    else if(n<32) cout<<16<<endl;
    else if(n<64) cout<<32<<endl;
    else cout<<64<<endl;
}