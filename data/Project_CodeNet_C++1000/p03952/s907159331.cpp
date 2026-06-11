#include <bits/stdc++.h>
#define sz size
#define pb push_back
#define mper make_pair
#define PI 3.14159
#define fe first
#define se second
#define ll long long
//#define forik(i, a, b) for(ll i = a; i <= b; ++i)
//#define vl vector<ll>
//#define pll pair<ll, ll>
#define mal ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
#define saken string
#define all(x) (x).begin(), x.end()
using namespace std;

const ll MAXN = 2e5 + 200;
ll n, x;
bool used[MAXN];
vector <ll> to;

int main(){

cin >> n >> x;

ll m = n;

if(n == 2 && x == 2) {
    cout << "Yes\n";
    for(int i = 1; i <= 3; ++i) {
        cout << i << '\n';
    }
    return 0;
}

if(x == 1 || x == 2 * n - 1) {cout << "No";}

else {

    cout << "Yes\n";


    n *= 2;

    n--;

    ll l = 0;
    ll r = 0;

    if(x != n - 1) {

        to.pb(x + 1);
        to.pb(x);
        to.pb(x - 1);
        to.pb(x + 2);

        l = m - 1;
        r = m + x;

    }

    else if(x == n - 1){

        to.pb(x - 2);
        to.pb(x);
        to.pb(x + 1);
        to.pb(x - 1);

        l = m - 2;
        r = m + 1;

    }

    for(auto it : to) {
        used[it] = 1;
    }

    ll ct = 0;

    for(int i = 1; i <= n; ++i) {
        if(!used[i]) {cout << i << '\n';used[i] = 1; ct++;}
        if(ct == l - 1) {break;}
    }

    for(auto it : to) {
        cout << it << '\n';
    }

    for(int i = 1; i <= n; ++i) {
        if(!used[i]) {cout << i << '\n';}
    }


}

return 0;
}

