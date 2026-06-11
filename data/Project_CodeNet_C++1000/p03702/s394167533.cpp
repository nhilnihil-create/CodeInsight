#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<char> vc;
typedef queue<int> qi;
typedef pair<ll,ll> P;
typedef vector<P> vp;
typedef vector<vl> mat;
#define sort(a) sort(a.begin(),a.end())
#define reverse(a) reverse(a.begin(),a.end())
#define pb push_back
#define ft first
#define sd second
#define elif else if
#define unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define mp make_pair
#define fr(i,n)for(ll i=0;i<(n);i++)
ll n,a,b;
ll h[100010];
bool binary(ll s){
    ll total = s*b,c = 0;
    fr(i,n){
        if(h[i]>total)
        c +=(h[i]-total+a-b-1)/(a-b);
    }
    if(c<=s) return true;
    else return false;
}
int main(){
    cin>>n>>a>>b;
    fr(i,n)cin>>h[i];
    ll ok = 1e10,ng = -1;
    while(ok-ng>1){
        ll middle = (ok+ng)/2;
        if(binary(middle)){
            ok = middle;
        }else{
            ng = middle;
        }
    }
    cout << ok << endl;
}