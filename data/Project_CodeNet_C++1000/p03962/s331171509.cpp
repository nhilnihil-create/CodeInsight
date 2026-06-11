#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    set<int>s;
    int a,b,c;cin >>a>>b>>c;
    s.insert(a);
    s.insert(b);
    s.insert(c);
    cout <<s.size()<<endl;
    return 0;
}