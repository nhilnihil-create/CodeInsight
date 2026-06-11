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
    int n, k;
    cin >> n >> k;
    vector<int> a;
    rep(i, n){ int tmp; cin >> tmp; a.push_back(tmp);}

    int a_max = *max_element(a.begin(),a.end());

    ll a_gcd = a[0];
    for (int i = 1; i < n; i++)
    {
        a_gcd = gcd(a[i], a_gcd);
    }
    if (k <= a_max && k%a_gcd == 0){
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

}

