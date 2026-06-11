#include <bits/stdc++.h>
using namespace std;

long long MOD=1000000007LL;

int main(){
	int N;
	long long ans=1;
	cin >> N;
	vector<int> T(N);
	vector<int> A(N);
	for(auto &i:T)cin >> i;
	for(auto &i:A)cin >> i;
	
	vector<bool> t(N,false);
	vector<bool> a(N,false);
	
	for(int i=0;i<N;i++){
		if(i==0)t[i]=true;
		else if(T[i-1]<T[i])t[i]=true;
	}
	for(int i=N-1;i>=0;i--){
		if(i==N-1)a[i]=true;
		else if(A[i+1]<A[i])a[i]=true;
	}
	
	for(int i=0;i<N;i++){
		if(t[i] && a[i]){
			if(T[i]!=A[i])ans*=0;
		}
		else if(t[i]){
			if(T[i]>A[i])ans*=0;
		}
		else if(a[i]){
			if(T[i]<A[i])ans*=0;
		}
		else{
			ans*=1LL*min(T[i],A[i]);
		}
		if(ans>=MOD)ans%=MOD;
	}
	cout << ans << endl;
	return 0;
}