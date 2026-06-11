#include<bits/stdc++.h>
#define int long long
using namespace std;

int qpow(int b,int e){
    if(!e)return 1;
    if(e&1) return qpow(b,e-1)*b;
    return qpow(b*b,e>>1);
}

int32_t main(){
    int n,k;
    cin>>n>>k;
    cout<<k*qpow(k-1,n-1)<<endl;

    return 0;
}
