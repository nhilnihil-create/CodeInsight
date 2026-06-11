#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<17,INF=1<<30;

int n,dat[2*MAX-1],lazy[2*MAX-1];

void init(int n_){
    n=1;
    while(n<n_) n*=2;
    for(int i=0;i<2*n-1;i++){
        dat[i]=0;
        lazy[i]=0;
    }
}

void eval(int k,int l,int r){
    
    if(lazy[k]!=0){
        dat[k]+=lazy[k];
        
        if(r-l>1){
            lazy[k*2+1]+=lazy[k]/2;
            lazy[k*2+2]+=lazy[k]/2;
        }
        
        lazy[k]=0;
    }
}

void add(int a,int b,int x,int k,int l,int r){
    eval(k,l,r);
    
    if(r<=a||b<=l) return;
    
    if(a<=l&&r<=b){
        lazy[k]+=(r-l)*x;
        eval(k,l,r);
    }
    
    else{
        add(a,b,x,2*k+1,l,(l+r)/2);
        add(a,b,x,2*k+2,(l+r)/2,r);
        dat[k]=dat[2*k+1]+dat[2*k+2];
    }
}

int query(int a,int b,int k,int l,int r){
    
    if(r<=a||b<=l) return 0;
    
    eval(k,l,r);
    
    if(a<=l&&r<=b) return dat[k];
    
    int vl=query(a,b,2*k+1,l,(l+r)/2);
    int vr=query(a,b,2*k+2,(l+r)/2,r);
    return vl+vr;
}

int main(){
    
    int N,M;cin>>N>>M;
    
    init(M+5);
    
    vector<int> A(N),cnt(M,0);
    
    for(int i=0;i<N;i++){
        cin>>A[i];
        A[i]--;
        if(i) cnt[A[i]]+=((A[i]+M-A[i-1])%M-1);
    }
    
    for(int i=0;i<N-1;i++){
        if(A[i]<A[i+1]){
            add(A[i]+1,A[i+1],1,0,0,n);
        }else{
            if(A[i]==M-1){
                add(0,A[i+1],1,0,0,n);
            }else{
                add(A[i]+1,M,1,0,0,n);
                add(0,A[i+1],1,0,0,n);
            }
        }
    }
    
    ll sum=0;
    
    for(int i=0;i<N-1;i++){
        if(A[i]<A[i+1]) sum+=A[i+1]-A[i];
        else sum+=(A[i+1]+1);
    }
    
    ll ans=sum;
    
    for(int i=0;i<M-1;i++){
        sum=sum-query(i,i+1,0,0,n)+cnt[i];
        //cout<<sum<<endl;
        ans=min(ans,sum);
    }
    
    /*for(int i=0;i<M;i++){
        cout<<query(i,i+1,0,0,n)<<endl;
    }*/
    
    cout<<ans<<endl;
    
}
