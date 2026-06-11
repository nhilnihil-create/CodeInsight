#include<bits/stdc++.h>
using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

#define pb push_back
#define mp make_pair
#define snd second
#define fst first
#define debug printf("--%d--\n",__LINE__)
#define ll long long int

int N, M, x[131072];


int solve(vi a, int n){
	int sum = 0, r = 0;
	for(int i=0;i<a.size();i++){
		sum += a[i];
		r += a[i]%2;
	}
	return (sum-max(r,n))/2;
}




int main(void){
	cin >> N >> M;
	for(int i=0;i<N;i++) cin >> x[i];
	sort(&x[0], &x[N]);
	
	vvi a(M);
	vi v;
	for(int i=0;i<M;i++) a[i] = v;
	int cnt = 0;
	for(int i=0;i<=N;i++){
		if (i==N || (i>0 && x[i-1]!=x[i])){
			a[x[i-1]%M].pb(cnt);
			cnt = 1;
		}else{
			cnt++;
		}
	}
	/*
	for(int i=0;i<M;i++){
		for(int j=0;j<a[i].size();j++){
			cout << " " << a[i][j];
		}cout << endl;
	}*/
	
	int ans = 0;
	for(int i=0;i<M;i++){
		int i1 = i;
		int i2 = (M - i1)%M;
		if (i2 < i1) break;
		if (i2==i1){
			int sum = 0;
			for(int j=0;j<a[i].size();j++) sum += a[i][j];
			ans += sum/2;
		}else{
			int sum1 = 0;
			for(int j=0;j<a[i1].size();j++) sum1 += a[i1][j];			
			int sum2 = 0;
			for(int j=0;j<a[i2].size();j++) sum2 += a[i2][j];			
			if (sum1 < sum2) swap(i1, i2);
			ans += min(sum1, sum2) + solve(a[i1], min(sum1, sum2));
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
