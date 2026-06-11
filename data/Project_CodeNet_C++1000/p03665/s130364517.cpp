#include <iostream>

using namespace std;

typedef long long ll;
/*
constexpr ll MOD=1000000007ll;

constexpr int MAX=510000;

ll fact[MAX],fact_inv[MAX];

ll power(ll a,ll b){
    ll res=1;
    while(b>0){
        if(b&1)res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}

ll comb(ll n,ll r){
    return (fact[n]*fact_inv[r])%MOD*fact_inv[n-r]%MOD;
}
*/

ll comb(int n,int r){
    
    ll num=1;
    for(int i=1;i<=r;i++){
        num=num*(n-i+1)/i;
    }
    

    return num;
    
}




int main() {
    
    /*
    int n=100000;
    fact[0]=1;
    for(int i=0;i<n;++i){
        fact[i+1]=fact[i]*(i+1)%MOD;
    }
    fact_inv[n]=power(fact[n],MOD-2);
    for(int i=n-1;i>=0;--i){fact_inv[i]=fact_inv[i+1]*(i+1)%MOD;}
    
    */
    
    int N,P;
    cin>>N>>P;
    //int A[N];
    
    int count=0;
    
    for(int i=0;i<N;++i){
        int tmp;
        cin>>tmp;
        if(tmp%2==1)++count;
    
    }
    
    //cout<<"N: "<<N<<"count: "<<count<<endl;
    
    ll cb1=0;
    
    for(int i=0;i<=count;++i){
        if(i%2==P){
            cb1+=comb(count,i);
        }
    }
  //  cout<<cb1<<endl;
    ll cb2=0;
    for(int i=0;i<=N-count;++i){
        //cout<<"N: "<<N<<" i: "<<i<<"comb: "<<comb(N-count,i)<<endl;
        cb2+=comb(N-count,i);
       
    }
   // cout<<cb2<<endl;
        
    cout<<cb1*cb2<<endl;
 
    return 0;
}
