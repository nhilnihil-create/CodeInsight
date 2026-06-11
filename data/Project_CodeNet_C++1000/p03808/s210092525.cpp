#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1005,INF=1000;

int main(){
    
    ll N;cin>>N;
    vector<ll> S(N);
    bool flag=true;
    ll sum=0,a=0;
    for(int i=0;i<N;i++){
        cin>>S[i];
        sum+=S[i];
        a+=(i+1);
    }
    if(sum%a!=0) flag=false;
    ll play=sum/a;
    for(int i=0;i<N-1;i++){
        if((play-(S[i+1]-S[i]))%N!=0) flag=false;
        if((play-(S[i+1]-S[i]))/N<0||(play-(S[i+1]-S[i]))/N>play) flag=false;
    }
    if((play-(S[0]-S[N-1]))%N!=0) flag=false;
    if((play-(S[0]-S[N-1]))/N<0||(play-(S[0]-S[N-1]))/N>play) flag=false;
    
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
