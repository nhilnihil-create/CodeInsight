#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define rforn(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define SQ(a) (a)*(a)


int main(){
	fast;
	map<int, int> m;
	for(int i = 0; i < 3; i++){
		int x;
		cin >> x;
		m[x]++;
	}
	
	if((m[5] == 2 && m[7] == 1)){
		cout << "YES" << endl;
	}else {
		cout << "NO" << endl;
	}
	return 0;
}
