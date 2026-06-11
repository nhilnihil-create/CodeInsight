//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF INT_MAX
#define LLINF LLONG_MAX
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
    for (T& x: vec) { is >> x; }
    return is;
}

int main() {
	ll ans = 0;
	ll tmp;
	int n; cin >> n;
	//n頂点m枝に対して隣接リストをつくる。
	int u, v;
	//vector< vector <int> > ls(n); //0-origin
	vector< vector <int> > ls(n+1); //1-origin
	vector< int > pa(n+1);
	pa[1] = 0;
	for(int i = 2; i<=n; i++){ 
		cin >> u; 
		ls[u].push_back(i); 
		pa[i] = u;
		//ls[v].push_back(u); //有向グラフならコメントアウトせよ
	}
	vector<int> dep(n+1);
	vector< vector <int> > chd(n+1);
	bool ch[n+1] = {};
	stack<int> q;
	q.push(1);
	while(!q.empty()){
		int now = q.top();
		if(!ch[now]){
			REP(j, (int)ls[now].size()){
				if(!ch[ls[now][j]]) q.push(ls[now][j]);
			}
		}
		else{
			sort(chd[now].rbegin(), chd[now].rend());
			int dd = -1;
			REP(i, chd[now].size()){
				dd = max(dd, chd[now][i] + i);
			}
			//cout << now << " " ; REP(i, chd[now].size()) cout << chd[now][i] << " "; cout << endl;
			dep[now] = dd + 1;
			chd[pa[now]].push_back(dd + 1);
			q.pop();
		}
		ch[now] = true;
	}

	//
	cout << dep[1] << endl;
}