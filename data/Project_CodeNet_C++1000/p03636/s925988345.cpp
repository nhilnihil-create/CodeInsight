#include <bits/stdc++.h> //C++の機能を「全て」読み込むための命令
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll inf=1e18;
const int N=2e5+10;
ll factorial(ll x){
    if(x==0||x==1) return 1;
    return x*factorial(x-1);
}
ll gcd(ll a ,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}

int main(){
    string s;
    cin >> s;

    int s_size = (int)s.size();

    string ans;
    ans += s.at(0);
    ans += to_string(s_size-2);
    ans += s.at(s_size-1);

    cout<<ans<<endl;


    return 0;
}