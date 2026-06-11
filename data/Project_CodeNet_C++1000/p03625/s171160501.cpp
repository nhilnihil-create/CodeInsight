#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; 
    ll x;
    ll a = 0, b = 0;
    map<ll, int> m;
    cin >> n;
    rep(i,n){
        cin >> x; 
        m[x]++;
    }
    map<ll, int>::reverse_iterator it = m.rbegin();
    for(it; it!=m.rend(); it++){
        if(it -> second > 1){
            if(a==0 && b == 0 && it->second >= 4){
                a = it->first;
                b = it->first;
                break;
            }
            else if(a == 0 && it->second >= 2){
                a = it->first;
            }
            else if(a != 0 && b==0 && it->second >=2){
                b = it->first;
                break;
            }
        }
    }
    cout << a*b;
    return 0;
}
