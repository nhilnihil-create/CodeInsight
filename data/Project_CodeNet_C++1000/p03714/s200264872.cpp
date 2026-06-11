#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int a[100005], b[100005], c[100005];
ll pref[100005], suff[100005];

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    
    sort(a+1, a+n+1);
    sort(c+1, c+n+1); reverse(c+1, c+n+1);
    
    multiset<int> ms;
    multiset<int> mm;
    for(int i = 1; i <= n; i++)
        ms.insert(a[i]);
    for(int i = 1; i <= n; i++)
        mm.insert(-c[i]);
    
    for(int i = 1; i <= n; i++){
        int x = b[i];
        int val = *ms.begin();
        pref[i] = pref[i-1];
        if(x > val){
            pref[i] += x-val;
            
            ms.erase(ms.begin());
            ms.insert(x);
        }
    }
    
    for(int i = n; i >= 1; i--){
        int x = b[i];
        int val = *mm.begin(); val *= -1;
        suff[i] = suff[i+1];
        if(x < val){
            suff[i] += val-x;
            mm.erase(mm.begin());
            mm.insert(-x);
        }
    }
    
    // for(int i = 1; i <= n; i++)
    //     cout << "pref[" << i << "] = " << pref[i] << endl;
    // for(int i = 1; i <= n; i++)
    //     cout << "suff[" << i << "] = " << suff[i] << endl;
    ll sumesq = 0, sumdir = 0;
    ll res = -1e18;
    for(int i = 1; i <= n; i++)
        sumesq += a[i];
    for(int i = 1; i <= n; i++)
        sumdir += c[i];
    for(int i = 0; i <= n; i++)
        res = max(res, sumesq + pref[i] - sumdir + suff[i+1]);
    cout << res << endl;
	return 0;
}