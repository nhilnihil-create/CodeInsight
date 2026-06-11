typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n,l;
    std::cin >> n>>l;
    std::vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    ll start = -1;
    for (int i = 0; i < n-1; i++) {
        if(a[i]+a[i+1]>=l){
            start = i;
            break;
        }
    }
    if(start==-1){
        std::cout << "Impossible" << std::endl;
        return 0;
    }
    
    std::cout << "Possible" << std::endl;
    
    vector<ll> ans;
    
    ans.push_back(start);
    
    for (int i = start-1; i >= 0; i--) {
        ans.push_back(i);
    }
    
    for (int i = start+1; i < n-1; i++) {
        ans.push_back(i);
    }
    
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[ans.size()-1-i]+1 << std::endl;
    }
    
    
    
}
