#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll stone[100010];
bool ch[100010];

ll dfs(int key, vector<vector<int>> &g){
    ch[key]=1;
    ll sum=0, mx=0;
    int cnt=0;
    for(int i=0; i<g[key].size(); ++i){
        if(!ch[g[key][i]]){
            ++cnt;
            ll p=dfs(g[key][i], g);
            if(p<0) return -1;
            sum += p;
            mx=max(mx, p);
        }
    }
    if(cnt==0) return stone[key];
    if(cnt==1){
        if(sum==stone[key]) return stone[key];
        else return -1;
    }
    ll num_pair=sum-stone[key];
    if(num_pair<0 || min(sum/2, sum-mx)<num_pair) return -1;
    stone[key] -= num_pair;
    return stone[key];
}

int main() {
	int N;
	cin >> N;
	for(int i=1; i<=N; ++i) cin >> stone[i];
	vector<vector<int>> v(N+1);
	for(int i=1; i<N; ++i){
	    int a, b;
	    cin >> a >> b;
	    v[a].push_back(b);
	    v[b].push_back(a);
	}
	if(N==2){
	    cout << (stone[1]==stone[2] ? "YES" : "NO") << endl;
	    return 0;
	}
	int t=1;
	while(v[t].size()==1) ++t;
	if(dfs(t, v)==0) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
