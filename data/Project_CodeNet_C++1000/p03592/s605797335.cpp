#define _LIBCPP_DEBUG 0
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef vector<int> vi;
typedef long long ll;


int main(){
    ll N,M,K;cin>>N>>M>>K;
    rep(i,0,N+1){
        rep(j,0,M+1){
            ll on=i*M+j*N-2*i*j;
            if(on==K){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
}




