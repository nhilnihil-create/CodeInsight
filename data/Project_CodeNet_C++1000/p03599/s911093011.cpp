#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;


int main(){
    vector<ll>x;
    vector<ll>y;
    ll A,B,C,D,E,F;
    cin >>A>>B>>C>>D>>E>>F;
    for (int a = 0; a <=F; ++a) {
        for (int b = 0; b <=F; ++b) {
            ll tmp=A*a*100+B*b*100;
            if(tmp>F)continue;
            x.push_back(tmp);
        }
    }
    for (int c = 0; c <= F; ++c) {
        for (int d = 0; d <= F; ++d) {
            if(c*C+d*D>F)continue;
            y.push_back(c*C+d*D);
        }
    }
    ll mx=0;
    ll wasu=0;
    ll sugar=0;
    for(auto i:x){
        for(auto j:y){
//            cout <<i <<" "<<j <<endl;
            if(i+j>F)continue;
            if(100*j>E*i)continue;
            if(j*wasu>=sugar*(i+j)){
                sugar=j;
                wasu=i+j;
            }
        }
    }
    cout <<wasu<<" "<<sugar<<endl;
    return 0;
}
