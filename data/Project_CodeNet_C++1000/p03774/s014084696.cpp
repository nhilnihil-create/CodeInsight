#include<iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define what_is(x) cerr << #x << " is " << x << endl;
#define MT make_tuple
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i,n) for (int i=0;i < n ; i++)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
ll inf=1e10+1;
int main(){
	int n ,m;
	cin >> n >> m;
	ll checkpointsx[m],studentsx[n],checkpointsy[m],studentsy[n];
	int i=0,j=0;
	while(i < n){
		cin >> studentsx[i] >> studentsy[i];
		i++;
	}
	FOR(j,m){
		cin >> checkpointsx[j] >> checkpointsy[j];
	}	
	ll ans[i];
	ll index=0;
	FOR(i,n){
		ans[i]=inf;
		index=0;
		FOR(j,m)
			if(abs(studentsx[i]-checkpointsx[j])+abs(studentsy[i]-checkpointsy[j]) < ans[i]){
				ans[i]=abs(studentsx[i]-checkpointsx[j])+abs(studentsy[i]-checkpointsy[j]);
				index=j;
			}
			cout << index +1<< "\n";
	}

	return 0;
}