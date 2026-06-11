#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std; //std::の省略のため
using ll = long long;

ll MOD = 1000000007;

int main()
{
    ll n;
    cin >> n;

    ll a[n];
    ll cnt[n] = {};

    bool judge = true;

    for(int i=0; i<n; i++)
        cin >> a[i];

    if(n%2 == 0){
        for(int i=0; i<n; i++){
            cnt[a[i]]++;
            if(cnt[a[i]] > 0 && a[i] == 0){
                judge = false;
                break;
            }
            else if(cnt[a[i]] > 2){
                judge = false;
                break;
            }
        }
        
    }
    else{
        for(int i=0; i<n; i++){
            cnt[a[i]]++;
            if(cnt[a[i]] > 1 && a[i] == 0){
                judge = false;
                break;
            }
            else if(cnt[a[i]] > 2){
                judge = false;
                break;
            }
        }
    }

    ll ans = 1;

    for(int i=0; i<(n/2); i++){
        ans *= 2;
        ans %= MOD;
    }

    if(judge){
        cout << ans << endl;
    }
    else{
        cout << 0 << endl;
    }

    }
