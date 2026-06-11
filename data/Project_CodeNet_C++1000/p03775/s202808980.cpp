#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(long long i=0;i<int(N);++i)
using ll = long long;
// const int INF = 2147483647;
const ll MOD = 1e9+7;
const ll INF = 1000000000000000000LL;
 
 
 int main() {
	 ll n;
	 cin >> n;
	 ll nin = INF;
	 for(ll i=1;i*i<=n;i++){
		 if(n%i==0){
			 ll bigger = n/i;
			 nin = min(nin,bigger);
		 }
	 }
	 //桁を数える
	 int keta=0;
	 while(nin>0){
		 nin/=10;
		 keta++;
	 }
	 cout << keta << endl;
	 return 0;
 }
