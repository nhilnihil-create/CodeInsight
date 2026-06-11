#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,A,ans,a,b,X[100000],Y[100000],rans;
vector<ll> v;
int main(void){
    cin>>n>>k;
    v.push_back(k);
    for(int i=29;i>0;i--){
        //cout<<((k>>i)&1);
        if(k>>i&1){
            A=(1<<i)-1;
            A+=ans;
            ans+=(1<<i);
            v.push_back(A);
        }
    }
    for(int i=0;i<n;i++)cin>>X[i]>>Y[i];
    //cout<<endl;
    for(auto x:v){
        ans=0;
        for(int i=0;i<n;i++){
            int ok=0;
            for(int j=29;j>=0;j--){
                if(X[i]>>j&1){
                    if((x>>j&1)==0){ok=1;break;}
                }
            }
            if(!ok)ans+=Y[i];
        }
        rans=max(rans,ans);
    }
    cout<<rans<<endl;
}
