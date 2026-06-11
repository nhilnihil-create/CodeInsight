#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
    ll n;
    cin >> n;
    int ans = 100;
    for(int i = 1;i <= sqrt(n);i++){
        ll j = n/i;
        if(n%i == 0){
            int f = max(to_string(i).size(),to_string(j).size());
            ans = min(ans,f);
        }
    }
    cout << ans;
}