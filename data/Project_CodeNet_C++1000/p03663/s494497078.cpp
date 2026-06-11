#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define debug(x) cout<<#x<<": "<<(x)<<endl

typedef long long ll;
const ll MAX_N = 1e9;

bool ques(ll n){
    cout<<"? "<<n<<endl<<flush;
    string ans;
    cin>>ans;
    return (ans=="Y");
}

void bin(ll l,ll r){
    if(l+1==r){
        cout<<"! "<<r<<endl;
        return;        
    }
    ll m = (l+r)/2;
    bool yes = ques(m*10);
    if(yes) bin(l,m);
    else bin(m,r);
}

int main(void){
    if(ques(MAX_N)){
        int d=MAX_N;
        while(d>1 && ques(d-1)) d/=10;
        cout<<"! "<<d<<endl;
    }else{
        int d=MAX_N;
        while(d/=10,!ques(d));
        bin(d,d*10);
    }
    return 0;
}
