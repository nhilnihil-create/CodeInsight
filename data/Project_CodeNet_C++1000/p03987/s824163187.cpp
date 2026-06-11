#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll a[200002];
    ll rev[200002];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        rev[a[i]] = i;
    }
    ll r[200002];
    priority_queue<int> quer;
    for(ll i = 0; i < n; i++){
        while(quer.size()){
            int lar = quer.top();
            if(lar > a[i]){
                quer.pop();
                r[rev[lar]] = i - 1;
            }
            else break;
        }
        quer.push(a[i]);
    }
    while(quer.size()){
        int lar = quer.top();
        quer.pop();
        r[rev[lar]] = n - 1;
    }
    ll l[200002];
    priority_queue<int> quel;
    for(ll i = n - 1; i >= 0; i--){
        while(quel.size()){
            int lar = quel.top();
            if(lar > a[i]){
                quel.pop();
                l[rev[lar]] = i + 1;
            }
            else break;
        }
        quel.push(a[i]);
    }
    while(quel.size()){
        int lar = quel.top();
        quel.pop();
        l[rev[lar]] = 0;
    }
    ll ans = 0;
    for(ll i = 0; i < n; i++) ans += a[i] * (i - l[i] + 1) * (r[i] - i + 1);
    cout << ans << endl;
}