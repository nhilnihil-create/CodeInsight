#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF = numeric_limits<long long>::max();
#define intf int_fast64_t
int main(){

    intf n,k;
    cin >>n >>k;
    vector<intf> l(n);
    for(auto &e :l) cin >>e;

    sort(l.begin(),l.end(),std::greater<intf>());

    cout << accumulate(l.begin(),l.begin()+k,0) <<endl;


}