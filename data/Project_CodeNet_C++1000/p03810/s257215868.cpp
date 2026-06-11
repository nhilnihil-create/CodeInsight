#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

ll gcd(ll v,ll b){
	if(v>b) return gcd(b,v);
	if(v==b) return b;
	if(b%v==0) return v;
	return gcd(v,b%v);
}

int main(){
    ll n;
    cin >> n;
    vector<ll>a(n);
    ll sm = 0;
    rep(i,n)cin >> a[i];
    rep(i,n)sm+=a[i];
    bool f = 1;
    if((sm-n)%2==1){
        cout << "First" << endl;
        return 0;
    }else{
        while(1){
        int cnt= 0;
        int k;
        rep(i,n){
            if(a[i]%2==1){
                cnt++;
                k = i;
            }
        }
        if(cnt!=1||a[k]==1){
            if(f)cout << "Second" << endl;
            else cout << "First" << endl;
            return 0;
        }
        a[k]--;
        int s = a[0];
        rep(i,n-1)s = gcd(s,a[i+1]);
        rep(i,n){
            a[i]/=s;
        }
        sm = 0;
        rep(i,n)sm+=a[i];
        if((sm-n)%2==1){
            if(f)cout << "Second" << endl;
            else cout << "First" << endl;
            return 0;
        }
        f = !f;
        }
    }  
    return 0;
}