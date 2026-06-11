#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main(){
    ll n; cin >> n;
	ll arr[n];
	for(ll i = 0; i < n; ++i){
		cin >> arr[i];
	}
	ll ans = 0, truer = 0;
	for(ll i = 1; i < n; ++i){
		if(truer == 1 && arr[i] >= arr[i - 1])continue;
		else if(truer == 2 && arr[i] <= arr[i - 1])continue;
		if(truer == 0){
			if(arr[i] > arr[i - 1])truer = 1;
			else if(arr[i] < arr[i - 1])truer = 2;
			else truer = 0;
		}else{
			ans++;
			truer = 0;
		}
	}
	cout << ans + 1;
    return 0;
}
