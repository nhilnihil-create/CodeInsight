#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
  	cin >> n >> m;
  	int in[n];
  	for (int i = 0; i < n; i++) in[i] = 0;
  	int num = n;
  	for (int i = 0; i < m; i++){
    	int a,b;
      	cin >> a >> b;
      	a--;
    	b--;
      	in[a]++;
     	in[b]++;
      	if (in[a]%2) num--;
      	else num++;
      	if (in[b]%2) num--;
      	else num++;
      	//cout << num << "\n";
    }
    //for(int i = 0; i < n; i++) cout << in[i] << "\n";
  	if (num == n) cout << "YES";
  	else cout << "NO";
}
