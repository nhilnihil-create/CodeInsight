#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define ep emplace_back
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
constexpr int mod=1000000007;
constexpr int mod1=998244353;
vector<int> dx={0,1,0,-1},dy={-1,0,1,0};
bool inside(int y,int x,int h,int w){ if(y<h && y>=0 && x<w && x>=0) return true; return false; }
template<class T> inline bool chmin(T& a, T b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b){ if(a < b){ a = b; return true; } return false; }






int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int h,w;cin >> h >> w;
	vector<string> s(h);
	rep(i,h) cin >> s.at(i);
	vector<int> cnt(26);
	rep(i,h){
		rep(j,w){
			cnt.at(s[i][j] - 'a')++;
		}
	}
	int cnt4 = 0, cnt2 = 0, cnt1 = 0;
	rep(i,26){
		cnt4 += cnt.at(i) / 4;
		cnt.at(i) %= 4;
	}
	rep(i,26){
		cnt2 += cnt.at(i) / 2;
		cnt.at(i) %= 2;
	}
	rep(i,26){
		cnt1 += cnt.at(i);
	}
	if(h % 2 == 0 && w % 2 == 0){
		if(cnt2 || cnt1) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
	else if(h % 2 == 0 || w % 2 == 0){
		if(w % 2 == 0) swap(h,w);
		if(cnt1 == 0 && cnt2 <= h / 2) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	else{
		if(cnt1 == 1 && cnt2 <= h / 2 + w / 2) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}
