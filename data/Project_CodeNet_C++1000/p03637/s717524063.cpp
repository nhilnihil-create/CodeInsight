#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;

#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> q;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


void solve(){
	llint n;
	cin >> n;
	vector<llint>v(n);
	llint cnt4=0;
	llint cnt2=0;
	for(int i=0;i<n;i++)cin >> v[i];
	for(llint x:v){
		if(x%4==0)cnt4++;
		else if(x%2==0)cnt2++;
	}
	if(n/2<=cnt4+cnt2/2)cout << "Yes";
	else cout << "No";
	cout << endl;


}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
