#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;


int main(){
    int N,T;cin>>N>>T;
    int a[1000000];
    rep(i,0,T)cin>>a[i];
    sort(a,a+T,greater<>());
    if((N+1)/2>=a[0])cout<<0<<endl;
    else{
        if(N%2==1)cout<<a[0]-(N-(N+1)/2)*2<<endl;
        else cout<<2*(a[0]-(N/2))-1<<endl;
    } 
}





