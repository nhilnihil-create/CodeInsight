#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
*/

const ll mod = 1e9+7;

// void chmod(ll &M){
//     if(M >= mod) M %= mod;
//     else if(M < 0){
//         M += (abs(M)/mod + 1)*mod;
//         M %= mod;
//     }
// }

int n, m;
vector<int> lans, rans;
int ep,ep2; // End point

vector<int> adj[100005];
vector<bool> used(100005, false);

void rdfs(int now){
	bool flg = true;

	for(auto e:adj[now]) if(used[e] == false) flg = false;
	if(flg){
		return;
	}

	for(auto e:adj[now]) if(used[e] == false){
		used[e] = true;
		ep = e;
		rans.push_back(ep);
		rdfs(ep);
		return;
	}

}

void ldfs(int now){
	bool flg = true;

	for(auto e:adj[now]) if(used[e] == false) flg = false;
	if(flg){
		cout << rans.size()+lans.size() << endl;
		reverse(lans.begin(), lans.end());
		for(int i=0; i<lans.size(); ++i){
			if(i) cout << " ";
			cout << lans[i];
		}
		for(int i=0; i<rans.size(); ++i){
			cout << " " << rans[i];
		}
		cout << endl;
		return;
	}

	for(auto e:adj[now]) if(used[e] == false){
		used[e] = true;
		ep = e;
		lans.push_back(ep);
		ldfs(ep);
		return;
	}

}



int main(){
	//cin.tie(0);
	//ios::sync_with_stdio(false);

	cin >> n >> m;

	for(int i=0; i<m; ++i){
		int a, b; cin >> a >> b;
		if(i == 0){
			used[a] = used[b] = true;
			rans.push_back(a);
			rans.push_back(b);
			ep = b;
			ep2 = a;
		}
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	rdfs(ep);
	ldfs(ep2);

	return 0;
}