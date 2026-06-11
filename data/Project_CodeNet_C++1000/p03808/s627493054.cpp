#include<bits/stdc++.h>
#include<unistd.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;

int main(){
    ll N;cin>>N;
    vector<int> A(N);
    ll S=0;
    REP(i, N){
        cin >> A[i];
        S+=A[i];
    }
    ll C=N*(N+1)/2;
    if(S%C!=0){
        cout<<"NO"<<endl;
        return 0;
    }
    C=S/C;
    ll cnt=0;
    //cout<<C<<endl;
    REP(i,N){
        if(C+A[i]-A[(i+1)%N]<0||(C+A[i]-A[(i+1)%N])%N!=0){
            cout<<"NO"<<endl;
            return 0;
        }
        ll k=(C+A[i]-A[(i+1)%N])/N;
        cnt+=k;
    }
    //cout<<cnt<<endl;
    if(cnt==C){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}
