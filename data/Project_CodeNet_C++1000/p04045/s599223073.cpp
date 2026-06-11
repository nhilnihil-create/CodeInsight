#include<cstdio>
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<cstring>
#include<cassert>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<limits>
#include<ctime>
#include<stack>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll N,K;
	cin >> N >> K;
	
	ll d[10];
	for(ll i=0;i<K;i++){
		cin >> d[i];
		}
		
    ll ans = N;
    for(ll i=N;i<=N*10;i++){
    	ll temp = i;
    	ll cnt = 0;
    	while(temp > 0){
    		ll num = temp%10;
    		for(ll k = 0; k<K;k++){
    			if(num == d[k]) cnt +=1;
    			}
    		temp/=10;
    	}
    	if(cnt == 0){
    		ans = i;
    		break;
    	}
    }
	
	cout << ans << endl;
	
	return 0;
	}