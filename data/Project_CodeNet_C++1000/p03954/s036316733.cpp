#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pb push_back
using namespace std;
ll n,b[200005],a[200005],ans;
bool check(ll x){
    for(int i=1; i<=n; i++)a[i] = (b[i] <= x);
    ll ind1,ind2;
    ind1 = ind2 = (n + 1) / 2;
    while(ind1 > 1){
        if(a[ind1] == a[ind1 - 1] || a[ind2] == a[ind2 + 1])return a[ind1];
        ind1--;
        ind2++;
    }
    ll sh = a[(n + 1) / 2];
    if((n / 2) % 2 == 1){
        return (1 ^ sh);
    }
    return sh;
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    n *= 2;
    n--;
    for(int i=1; i<=n; i++){
        cin >> b[i];
    }
    ll l =1,r = n,mid;
    
    while(r >= l){
        mid = (l + r) / 2;
        if(check(mid)){
            r = mid - 1;
            ans = mid;
        }
        else {
            l = mid + 1;
        }
    }
    
    cout << ans << endl;
    
    
    
    return 0;
}
