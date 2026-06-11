#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define debug(x) cout<<#x<<": "<<(x)<<endl

typedef long long ll;

bool ques(ll n){
    cout<<"? "<<n<<endl<<flush;
    string ans;
    cin>>ans;
    return (ans=="Y");
}

bool pow10(ll n){
    ll d=1;
    rep(i,10){
        d*=10;
        if(n==d)return true;
    }
    return false;
}

void select(ll l,ll r){
    if(l==0)l=1;
    while(l<=r){
        if(ques(l*10)){
            cout<<"! "<<l<<endl;
            return;
        }
        l++;
    }
}

void bin(ll l,ll r){
    if(l>1e10){
        cout<<"! 1"<<endl;
        return;
    }
    ll m = (l+r)/2;
    bool yes = ques(m);
    if(m%10==9 && yes && (pow10(r)^ques(r))){
        select(m-9,m);
        return;
    }

    if(m+1==r && yes) bin(m*10,(m+1)*10); 
    else if(yes) bin(m,r);
    else bin(l,m);
}

int main(void){
    bin(0,10);
    return 0;
}
