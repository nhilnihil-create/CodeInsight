#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<utility>
#include<cstdio>
using namespace std;
#define rep(i,x,n) for(int i=x;i<n;i++)
using ll=long long;

double distance(int xs,int ys,int xg,int yg){
    int ss=(xs-xg)*(xs-xg)+(ys-yg)*(ys-yg);
    return pow(ss,1/2);
}
int main(){
    int n; cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    ll ans=0;
    bool flag=true;
    if(n%2==0){
        vector<int> B(n,0);
        rep(i,0,n){
            B[(A[i]-1)/2]++;
        }
        rep(i,0,n/2){
            if(B[i]!=2) flag=false;
        }
        rep(i,n/2,n){
            if(B[i]!=0) flag=false;
        }
        if(flag){
            ans=1;
            rep(i,0,n/2){
                ans*=2;
                ans%=1000000007;
            }
        } 
    }else{
        vector<int> C(n,0);
        rep(i,0,n){
            C[A[i]/2]++;
        }
        rep(i,0,(n+1)/2){
            if(i==0&&C[i]!=1) flag=false;
            else if(i!=0&&C[i]!=2) flag=false;
        }
        rep(i,(n+1)/2,n){
            if(C[i]!=0) flag=false;
        }
        if(flag){
            ans+=1;
            rep(i,0,n/2){
                ans*=2;
                ans%=1000000007;
            }
        }
    }
    cout<<ans<<endl;
}