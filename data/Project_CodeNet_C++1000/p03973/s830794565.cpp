typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n;
    std::cin >> n;
    vector<ll> a(n);
    ll dif = 1;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if(a[i]%dif == 0){
            res += a[i]/dif-1;
        }else{
            res += a[i]/dif;
        }
        if(a[i]==dif || dif==1){
            dif++;
        }
    }
    std::cout << res << std::endl;
}
