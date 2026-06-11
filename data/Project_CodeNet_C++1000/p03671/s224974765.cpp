#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int in() {int x; cin>>x; return x;}
ll lin() {ll x; cin>>x; return x;}
string sin() {string x;cin>>x;return x;}
using graph = vector<vector<int>>;
using graph2 = vector<vector<pair<int, int>>>;

bool ifprime(int x){
    if(x==1)return false;
    if(x==2)return true;
    if(x%2==0)return false;
    for(int i=2;i*i<=x;i++){if(x%i==0)return false;}
    return true;
}
ll mod(ll x, ll y){if(x>=0||x%y==0) return x%y;return y+x%y;} //mod including minus
ll dv0(ll x, ll y){if(x>=0||x%y==0)return x/y;return x/y-1;} //rnd down
ll dv1(ll x, ll y){if(x%y==0) return dv0(x,y);return dv0(x,y)+1;} //rnd up

//Start from Here
int main(){
    int a, b, c;
    cin>>a>>b>>c;
    int m=a+b+c;
    int d=max(a, b);
    d=max(d, c);
    cout<<m-d<<endl;
}