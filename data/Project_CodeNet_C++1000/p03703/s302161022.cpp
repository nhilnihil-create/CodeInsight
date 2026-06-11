#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18,INF=1<<30;

int n,dat[2*MAX-1];

void init(int n_){
    n=1;
    while(n<n_) n*=2;
    for(int i=0;i<2*n-1;i++){
        dat[i]=0;
    }
}

void update(int k,int a){
    k+=n-1;
    dat[k]=a;
    
    while(k>0){
        k=(k-1)/2;
        dat[k]=dat[k*2+1]+dat[k*2+2];
    }
}

int query(int a,int b,int k,int l,int r){
    
    if(r<=a||b<=l) return 0;
    if(a<=l&&r<=b) return dat[k];
    else{
        int vl=query(a,b,2*k+1,l,(l+r)/2);
        int vr=query(a,b,2*k+2,(l+r)/2,r);
        return vl+vr;
    }
}


bool compare(pair<ll,int> a,pair<ll,int> b){
    return a.second<b.second;
}

int main(){
    
    int N,K;cin>>N>>K;
    vector<ll> A(N);
    vector<pair<ll,int>> S(N+1);
    for(int i=0;i<N;i++){
        cin>>A[i];
        A[i]-=K;
        S[i+1].first=S[i].first+A[i];
        S[i+1].second=i+1;
    }
    
    sort(all(S));
    
    for(int i=0;i<N+1;i++){
        S[i].first=i;
    }
    
    sort(all(S),compare);
    
    init(N+1);
    
    ll ans=0;
    
    update(S[N].first,1);
    
    for(int i=N-1;i>=0;i--){
        ans+=query(S[i].first,n,0,0,n);
        update(S[i].first,1);
    }
    
    cout<<ans<<endl;
}
