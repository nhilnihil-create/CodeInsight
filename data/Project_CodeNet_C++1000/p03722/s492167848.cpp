#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, m; 
  cin >> n >> m;
  
	int a[2010], b[2010];
  
  long long c[2010] , dist[1010];
	
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i] >> c[i];
      
		c[i] = -c[i];
		a[i]--, b[i]--;
	}
	
	
	dist[0] = 0;
  
  for(int i=1;i<n;i++){
    dist[i] = 1000000000000000000000009;
  }
     
	for (int j = 0; j < n-1; j++) {
      
		for (int i = 0; i < m; i++) {
			if (dist[a[i]] == 1000000000000000000000009) continue;
          
			if (dist[b[i]] > dist[a[i]] + c[i]) {
				dist[b[i]] = dist[a[i]] + c[i];
			}
		}
	}
  
	long long ans = dist[n-1];

	bool abc[1010];
  
  for(int i=0;i<n;i++){
    abc[i] = false;
  }
  
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {
			if (dist[a[i]] == 1000000000000000000000009) continue;
			if (dist[b[i]] > dist[a[i]] + c[i]) {
				dist[b[i]] = dist[a[i]] + c[i];
              
				abc[b[i]] = true;
			}
			if (abc[a[i]]) abc[b[i]] = true;
		}
	}

	if (abc[n-1])
		cout << "inf" << endl;
	else
		cout << -ans << endl;
}
