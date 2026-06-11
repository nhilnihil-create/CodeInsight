#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line

//const ll mod = 1e9+7;
//const ll mod = 998244353;
 
int main()
{
	string s;
	cin >> s;
	REV(s);

	vector<string> a={"dream","dreamer","erase","eraser"};
	rep(i,4) REV(a[i]);
	int count = 0;
	
	while(count < s.size()){
		bool check = false;
		rep(i,4){
			string now = s.substr(count, a[i].size());
			if(s.substr(count,a[i].size()) == a[i]){
				count += a[i].size();
				check = true;
				break;
			}
		}
		if(check) continue;
		if(!check){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}
