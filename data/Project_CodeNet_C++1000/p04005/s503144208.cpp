#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef unsigned long long ll;
int main(){
vector<ll> vec(3);
rep(i,3) cin >> vec[i];
sort(vec.begin(),vec.end());
ll ans;
if(vec[0] % 2 == 0|| vec[1] % 2 == 0 || vec[2] % 2 == 0) ans = 0;
else ans = vec[0] * vec[1];
cout << ans << endl;;
}