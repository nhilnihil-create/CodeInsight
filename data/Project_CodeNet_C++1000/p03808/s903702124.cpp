#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    while (cin >> n) {
        vector<ll> v(n);
        ll sum = 0;
        for (auto &i : v) {
            cin >> i;
            sum += i;
        }
        if (n == 1) {
            cout << "YES\n";
            continue;
        }
        ll sig = (n * (n + 1)) / 2;
        if (sum % sig) {
            cout << "NO\n";
            continue;
        }
        sum /= sig;
        ll norm = sum;
        ll nd = 0;
        int f = 0;
        for (int i = 0 ; i < n ; i++) {
            ll dif = v[(i + 1) % n] - v[i];
            //cout << dif <<' '<<norm<<endl;
            if (dif > norm) {
                f = 1;
                break;
            }
            dif = norm - dif;
            if (dif % n) {
                f = 1;
                break;
            }
            nd += dif / n;
        }
        //cout << f <<' '<<nd<<' '<<sum<<endl;
        if (f == 1 || nd != sum) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
}