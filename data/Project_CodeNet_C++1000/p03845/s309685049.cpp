#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n, x, y, d, sum=0;
  	cin >> n;
  	vector<int> a(n);
  	for(int i=0;i<n;i++){
    	cin >> a[i];
    	sum+=a[i];
    }
  	cin >> d;
  	for(int i=0;i<d;i++){
      	cin >> x >> y;
      	cout << sum+(y-a[x-1]) << "\n";
    }
}