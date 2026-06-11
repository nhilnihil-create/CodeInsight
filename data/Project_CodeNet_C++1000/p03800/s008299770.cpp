#include<bits/stdc++.h>
using namespace std;
 
#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define SORT(c) sort((c).begin(),(c).end())
#define IINF INT_MAX
#define LLINF LLONG_MAX
#define DEBUG false
#define MOD 1000000007
 
typedef long long ll;
typedef pair<int, int> ii;

int main() {

	int n;
	string s;
	cin >> n >> s;
	rep(i, 4){
		vector<int> v(n+2);
		v[0] = i % 2;
		v[1] = i / 2;
		
		rep(index, n){
			if(v[index+1]){ //正直
				if(s[index] == 'o') v[index+2] = v[index];
				else v[index+2] = (v[index] + 1) % 2;
			}else{
				if(s[index] == 'o') v[index+2] = (v[index] + 1) % 2;
				else v[index+2] = v[index];
			}
		}
		
		if(v[0] == v[n] && v[1] == v[n+1]){
			REP(index, 1, n+1){
				cout << (v[index] ? 'S' : 'W');
			}
			cout << endl;
			return 0;
		}
	}
	
	cout << -1 << endl;
	
	return 0;
}