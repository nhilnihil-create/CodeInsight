#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll k;
int main(){
	cin>>k;
	ll a[55];
	for(int i=0;i<50;i++) a[i] = i+k/50;
	for(int i=0;i<k%50;i++){
		a[0]+=50LL;
		for(int i=1;i<50;i++) a[i]--;
		sort(a,a+50);
	}
	cout << 50 << endl;
	for(int i=0;i<50;i++){
		cout << a[i] << (i==49?'\n':' ');
	}
}