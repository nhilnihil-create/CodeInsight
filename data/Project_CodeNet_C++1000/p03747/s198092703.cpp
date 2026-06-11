#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=100003,INF=1<<30;

int main(){
    
    int N;
    ll L,T;cin>>N>>L>>T;
    ll G;
    vector<ll> X(N),W(N),goal(N);
    for(int i=0;i<N;i++){
        cin>>X[i]>>W[i];
        if(W[i]==1){
            goal[i]=(X[i]+T)%L;
        }else{
            goal[i]=(L+X[i]-T%L)%L;
        }
        
        if(i==0) G=goal[i];
    }
    sort(all(goal));
    
    ll cnt1=0;
    for(int i=0;i<N;i++){
        if(W[i]==W[0]) continue;
        ll dis=2*T;
        if(W[0]==1){
            if(dis<X[i]-X[0]) continue;
            dis-=(X[i]-X[0]);
        }else{
            if(dis<L+X[0]-X[i]) continue;
            dis-=(L+X[0]-X[i]);
        }
        cnt1++;
        
        cnt1+=(dis/L);
        
        cnt1%=N;
    }
    
    int app=0;
    
    for(int i=0;i<N;i++){
        if(goal[i]==G) app++;
    }
    
    if(app==1){
        for(int i=0;i<N;i++){
            if(goal[i]==G){
                int j;
                if(W[0]==2){
                    j=(i+cnt1)%N;
                }else{
                    j=(N+i-cnt1)%N;
                }
                
                //cout<<i<<" "<<j<<endl;
                
                for(int k=0;k<N;k++){
                    cout<<goal[(j+k)%N]<<endl;
                }
                
                return 0;
            }
        }
    }else{
        if(W[0]==1){
            for(int i=1;i<N;i++){
                if(goal[i]==G&&goal[i-1]==G){
                    int j;
                    if(W[0]==2){
                        j=(i+cnt1)%N;
                    }else{
                        j=(N+i-cnt1)%N;
                    }
                    
                    //cout<<i<<" "<<j<<endl;
                    
                    for(int k=0;k<N;k++){
                        cout<<goal[(j+k)%N]<<endl;
                    }
                    
                    return 0;
                }
            }
        }else{
            for(int i=0;i<N;i++){
                if(goal[i]==G){
                    int j;
                    if(W[0]==2){
                        j=(i+cnt1)%N;
                    }else{
                        j=(N+i-cnt1)%N;
                    }
                    
                    //cout<<i<<" "<<j<<endl;
                    
                    for(int k=0;k<N;k++){
                        cout<<goal[(j+k)%N]<<endl;
                    }
                    
                    return 0;
                }
            }
        }
    }
    
    
}

