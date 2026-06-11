 #include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;
 const int INF = 2147483647;
 const ll MOD = 1000000007;
 // const ll INF = 1000000000000000000LL;
 
 int main(){
	 int n;
	 cin >> n;
	 vector<ll> a(n);
	 rep(i,n) cin >> a[i];
	 sort(a.begin(),a.end());
	 vector<ll> sum(n+1);
	 for(int i=1;i<=n;i++){
		 sum[i] = sum[i-1]+a[i-1];
	 }
	 int k;
	 bool flag = true;
	 for(int i=1;i<n;i++){
		//  cout << sum[i] << ',' << a[i] << endl;
		 if(sum[i]*2>=a[i]&&flag) {
			 k = i-1;
			 flag = false;
		 }
		 else if(sum[i]*2<a[i]){
			 flag = true;
		 }
	 }
	 cout << n - k << endl;
	//  cout << n - k << endl;
   return 0;	
 }