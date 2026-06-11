#include <bits/stdc++.h>


#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
const int MD = (int)1e9 + 7; typedef vector<ll> VL;
void dbg(){ cerr << "\n"; }  template <class T, class ...T2>
void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
template <class T, class T2> void amax(T& a,T2 b){ if(a < b) a = b;}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	string s;
	cin >>s;
	vector<VI> sk(26);
	rep(i, sz(s)){
		sk[s[i]-'a'].push_back(i);
	}
	for(auto& zs: sk){
		int m=sz(zs);
		if(m < 2) continue;
		rep(i, m) rep2(p, 1, 28){
			if(i+p>=m) break;
			int und = zs[i+p] - zs[i] + 1;
			//dbg(zs[i+p],zs[i]);
			if(und < (p+1) * 2 ){
				cout << zs[i]+1 <<" " <<zs[i+p]+1 <<"\n";
				return 0;
			}
		}
	}
	cout<<"-1 -1\n";
	return 0;
}
