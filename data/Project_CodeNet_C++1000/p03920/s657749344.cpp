#include <bits/stdc++.h>
using namespace std;
multiset<int>st;
int main(){
	long long n;
	cin >> n;
	long long now = 1;
	long long sum = 0;
	while(sum < n){
		sum+=now++;
	}
	long long diff = sum-n;
	for(long long i = 1; i < now; ++i){
		if(i != diff)printf("%lld\n", i);
	}
}