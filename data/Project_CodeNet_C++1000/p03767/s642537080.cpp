#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF = numeric_limits<long long>::max();
#define intf int_fast64_t
int main(){
    intf n,ans=0;
    cin >>n;
    vector<intf> a(3*n);
    for(auto &e:a) cin >>e;

    sort(a.begin(),a.end(),std::greater<intf>());

    for(int i=1;i<2*n;i+=2){
        ans +=a[i];
    }
    cout << ans <<endl;
}