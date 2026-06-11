#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

ll combi(ll n, ll k){
    if(n==k || k==0) return 1;
    else return combi(n-1, k-1) + combi(n-1, k);
}

int main(){
    int n, p; cin >> n >> p;
    vector<int> a(n);
    ll odd=0, even=0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i]%2==0) even++;
        if(a[i]%2!=0) odd++;
    }
    ll odd_count=0;
    if(odd>0)
        odd_count  = pow(2, odd-1);
    else
        odd_count = 0;
    ll even_count=0;
    even_count = pow(2, even);
    unsigned long long ans=0;
    if(p==0){
        if(odd>0)
            ans = odd_count*even_count;
        else
            ans = even_count;
    }else if(p==1) ans = odd_count*even_count;
    cout << ans << endl;
    return 0;
}