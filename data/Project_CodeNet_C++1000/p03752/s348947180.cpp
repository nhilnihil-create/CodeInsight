#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
	ll n;
    ll k;
    cin >> n >> k;
    ll inp;
    vector<ll> a(n);
    vector<ll> perm(n);
    for(ll i = 0; i < n; i++){
        cin >> inp;
        a.at(i) = inp;
        if(i < n - k) perm.at(i) = 0;
        else perm.at(i) = 1;
    }

    ll ans = 20000000000 * n;
    do{
        vector<ll> dummy = a;
        ll sum = 0;
        for(ll i = 0; i < n; i++){
            if(perm.at(i) == 1 && i > 0){
                ll max = * max_element(dummy.begin(), dummy.begin() + i);
                if(dummy.at(i) <= max){
                    sum += max - dummy.at(i) + 1;
                    dummy.at(i) = max + 1;
                }
            } 
        }
        ans = min(ans, sum);
    }while(next_permutation(perm.begin(),perm.end()));
    

    cout << ans << endl;
  	return 0;
}
