#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll k;
ll n;
vector< ll > a;
int main()
{
        cin >> k;
        n = 50;
        if(k >= 50){
        ll V = (k/n);
        a.resize(n, V);
        for(ll i=0;i<n;i++) a[i] += i;
        ll rems = k%n;
        for(ll i=0;(i<n) && (rems); i++) {
                a[i] += n;
                for(ll j=0;j<n;j++) {
                        if(j==i) continue;
                        a[j] -= 1;
                }
                rems--;
        }
        cout << a.size() << "\n";
        for(auto &i: a) cout << i << " ";
        }else {
                a.resize(n, 0);
                for(ll i=0;i<n;i++) a[i] += i;
                ll rems = k;
                for(ll i=0;(i<n) && (rems); i++) {
                a[i] += n;
                for(ll j=0;j<n;j++) {
                        if(j==i) continue;
                        a[j] -= 1;
                }
                rems--;
        }
        cout << a.size() << "\n";
        for(auto &i: a) cout << i << " ";
        }
        return 0;
}
