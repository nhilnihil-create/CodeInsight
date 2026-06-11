#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007;

int main(){
    
    int N;cin>>N;
    priority_queue<ll> Q1,Q2;
    ll sum1=0,sum2=0;
    vector<ll> S(N*3),T1(3*N,0),T2(3*N,0);
    for(int i=0;i<3*N;i++){
        cin>>S[i];
    }
    for(int i=0;i<N;i++){
        sum1+=S[i];
        Q1.push(-S[i]);
    }
    T1[N-1]=sum1;
    for(int i=N;i<2*N;i++){
        Q1.push(-S[i]);
        T1[i]=T1[i-1]+S[i]+Q1.top();
        Q1.pop();
    }
    for(int i=3*N-1;i>=2*N;i--){
        sum2+=S[i];
        Q2.push(S[i]);
    }
    T2[2*N]=sum2;
    for(int i=2*N-1;i>=N;i--){
        Q2.push(S[i]);
        T2[i]=T2[i+1]+S[i]-Q2.top();
        Q2.pop();
    }
    ll ans=T1[N-1]-T2[N];
    for(int i=N-1;i<=2*N-1;i++){
        ans=max(ans,T1[i]-T2[i+1]);
    }
    cout<<ans<<endl;
}
