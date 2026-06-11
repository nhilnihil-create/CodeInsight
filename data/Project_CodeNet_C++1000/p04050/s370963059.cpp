#include <bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
#define MP make_pair
#define ld long double
 
using namespace std;
 
const int N = 1e5 + 12;
const ll mod = 1e9 + 7;

int n, m, gg[N];
vector<int> g[N], a, b;

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
    	int x;
    	cin >> x;
    	gg[i] = x;
    	g[(x & 1)].push_back(-x);
    }

    if(m == 1){
    	if(gg[1] == 1){
    		cout << "1\n1\n1";
    	}            
    	else{
    		cout << gg[1] << "\n";
    		cout << "2\n";
    		cout << gg[1] - 1 << " " << 1;
    	}
    	return 0;
    }
    if(m == 2){
    	cout << gg[1] << " " << gg[2] << "\n";
    	
    	if(min(gg[1], gg[2]) == 1){
    		cout << "1\n" << gg[1] + gg[2];
    		return 0;
    	}
    	
    	cout << "2\n";
    	cout << gg[1] - 1 << " " << gg[2] + 1;
    	return 0;
    }

    sort(g[0].begin(), g[0].end());
    sort(g[1].begin(), g[1].end());

    if(g[1].size() > 2){
    	cout << "Impossible";
    }
    else{
    	if(g[1].size() >= 1){
    		a.push_back(-g[1][0]);
    	}
    	for(int u: g[0]){
    		a.push_back(-u);
    	}
    	if(g[1].size() == 2){
    		a.push_back(-g[1][1]);
    	}

    	for(int i = 0;i < (int)a.size();i++){
    		if(i == 0){
    			b.push_back(a[i] - 1);
    		}
    		else{
    			if(b.back() == 0){
    				b.pop_back();
    			}
    			b.push_back(a[i]);
    		}
    	}
    	b[(int)b.size() - 1] += 1;

    	for(int u: a){
    		cout << u << " ";
    	}
    	cout << "\n" << b.size() << "\n";
    	for(int u: b){
    		cout << u << " ";
    	}
    }
    return 0;
}