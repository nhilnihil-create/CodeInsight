#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
 int n, t; cin >> n >> t;
 int arr[n + 1];
 for(int i =0; i < n; ++i) cin >> arr[i];
 ll ans = 0;
 for(int i = 1; i < n;++i){
   ans += (ll)min(arr[i] - arr[i -1],t);
 }
 cout << ans + (ll)t<< '\n';
}