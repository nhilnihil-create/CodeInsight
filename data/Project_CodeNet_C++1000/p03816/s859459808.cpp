#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	int n;cin>>n;
	map<ll,ll> p;
	for(int i = 0; i < n; i++) {
		ll key;
		cin>>key;
		auto it = p.find(key);
		if(it != p.end()){
			p[key]++;
			if(p[key] >= 3){
				p[key] = 1;
			}
		}
		else{
			p[key] = 1;
		}
	}
	int c = 0;
	for(auto i = p.begin(); i != p.end(); i++) {
		if(p[i->first] == 2){
			c++;
		}
	}

	if(c % 2 == 0){
		cout << p.size() << endl;
	}
	else{
		cout << p.size() - 1 << endl;
	}

	return 0;
}