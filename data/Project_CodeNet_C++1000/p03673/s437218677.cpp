#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
const int inf=1010001000;
const ll  INF=1001000100010001000;
const int mod=(int)1e9+7;

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    deque<int> b;
    rep(i,0,n){
        cin>>a.at(i);
    }
    rep(i,0,n){
        if(i%2==0)b.push_front(a.at(i));
        else b.push_back(a.at(i));
    }
    if(n%2==0)reverse(all(b));
    rep(i,0,n){
        cout<<b.at(i)<<' ';
    }
return 0;
}