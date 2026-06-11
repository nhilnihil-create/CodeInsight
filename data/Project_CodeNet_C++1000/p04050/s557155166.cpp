#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, mod = (int)1e9 + 7;

int n, m, q, ans[N];
vector< int > v[2];

int main(){    
	cin >> n >> m;
	if(m == 1){
		int x;
		cin >> x;
		if(x == 1)
			cout << x << endl << 1 << endl << 1;
        else
        	cout << x << endl << 2 << endl << x - 1 << " " << 1;
		return 0;
	}
	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		v[x&1].pb(x);
	}                             
	sort(v[0].begin(),v[0].end());
	sort(v[1].begin(),v[1].end());
	
	if(v[1].size() > 2){
		cout << "Impossible" ;
		return 0;
	}                          
	
	if(!v[1].empty())
       	cout << (ans[q++] = v[1][0]) << " ";
	for(int i = 0; i < v[0].size(); i++)
		cout << (ans[q++] = v[0][i]) << " ";
	for(int i = 1; i < v[1].size(); i++)
		cout << (ans[q++] = v[1][i]) << " ";
	cout << endl; 
	ans[0]--;
	ans[q - 1]++;
	if(ans[0] == 0){
		cout << q - 1 << endl;
		for(int i = 1; i < q; i++)
			cout << ans[i] << " ";
	}else{
		cout << q << endl;
		for(int i = 0; i < q; i++)
			cout << ans[i] << " ";
	}//das
	return 0;
}
