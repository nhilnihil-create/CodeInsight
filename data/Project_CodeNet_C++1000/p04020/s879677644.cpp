#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;



int main(){
    ll n;cin>>n;
    ll a[100010],an=0;
    rep(i,0,n)cin>>a[i];
    a[n]=0;
    rep(i,0,n){
        an+=a[i]/2;
        if(a[i]%2==1&&a[i+1]!=0){an++;a[i+1]--;}
    }
    cout<<an<<endl;
}





