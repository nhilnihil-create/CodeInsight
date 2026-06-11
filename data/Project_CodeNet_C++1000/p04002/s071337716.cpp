#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll s[9];
ll h,w,n;
map<P,ll>mp;
int main(void){
    cin>>h>>w>>n;
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(a-j>0&&b-k>0&&a-j<=h-2&&b-k<=w-2){
                    mp[P(a-j,b-k)]++;
                }
            }
        }
    }
    ll tot=0;
    for(auto x:mp){
        s[x.second-1]++;
        tot++;
    }
    cout<<(h-2)*(w-2)-tot<<endl;
    for(int i=0;i<9;i++){
        cout<<s[i]<<endl;
    }
}
