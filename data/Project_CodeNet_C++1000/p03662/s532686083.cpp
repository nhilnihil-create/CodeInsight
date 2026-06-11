#include<iostream>
#include<vector>
using namespace std;


int n, l, r, q[100010], vis[100010];
vector <int> e[100010];

int main()
{
	cin >> n;
	for (int i = 1, u, v; i < n; i++) {
      
		cin >> u >> v;
      
		e[u].push_back(v), e[v].push_back(u);
	}
	l = 1, r = 0;
	vis[1] = 1; vis[n] = 2;
	q[++r] = 1; q[++r] = n;
	while (l <= r) {
		int u = q[l++];
		for (int v : e[u]) {			
			if (!vis[v]) {
				vis[v] = vis[u];
				q[++r] = v;
			}
		}
	}
	int sum1 = 0, sum2 = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 1)sum1++;
		else sum2++;
	}
  
	if(sum1 > sum2){
      cout << "Fennec" << endl;
    }
  
  else{
    cout << "Snuke" << endl;
  }

	
}
