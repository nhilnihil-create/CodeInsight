#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

ll k;

int main(){
    cin>>k;
    ll x=k/50,y=k%50;
    cout<<50<<endl;
    rep(i,50){
        if(i)cout<<" ";
        cout<<(i<y?i+x-y+51:i+x-y);
    }
    cout<<endl;
}