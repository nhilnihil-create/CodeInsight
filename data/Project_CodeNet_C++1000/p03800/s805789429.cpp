#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
const int MD = (int)1e9 + 7;
void dbg(){ cerr << "\n"; }  template <typename T,typename ...T2>
void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
template <class T> void amin(T& a,T b){ a=min(a,b);}


int main(){
	//cin.tie(0); ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin >>n >>s;
	s = s+s;
	rep(i, 4){
		vector<uint8_t> t(n+4);
		t[0] = i&1;
		t[1] = i>>1 &1;

		rep2(j, 2, n+4){
			if(!t[j-1]) t[j] = s[j-1]=='o'? t[j-2]: !t[j-2];
			else        t[j] = s[j-1]=='o'? !t[j-2]: t[j-2];
		}
		//for(auto x :t) printf("%c ",x?'T':'F'); puts("");
		if(t[0]==t[n] && t[1]==t[n+1] && t[2]==t[n+2]){
			rep(j, n){
				cout << (t[j]? 'W':'S');
			}
			cout <<"\n";
			return 0;
		}   
	}
	
	cout << -1 <<endl;
	return 0;
}