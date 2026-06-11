#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


int main()
{
    int k, t;
    cin >> k >> t;
    vector<int> a(t);
    int csum = 0;
    int cmax = 0;
    rep(i, t){
        cin >> a[i];
        csum += a[i];
        cmax = max(cmax, a[i]);
    }
    int diff = csum - cmax;
    //diff*2+1日まではOK

    int ans;
    if (diff*2 + 1 > k){
        ans = 0;
    } else {
        ans = k - (diff*2+1);
    }

    cout << ans << endl;
}

