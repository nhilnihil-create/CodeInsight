#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N];
bool mark[N];

int main() {
	int n, x;
  	cin >> n >> x;
  	cout << (x != 1 && x != 2 * n - 1? "Yes": "No") << endl;
	if(x != 1 && x != 2 * n - 1) {
    	a[n] = x;
      	a[n + 1] = x + 1;
      	a[n - 1] = x - 1;
      	mark[x] = true;
      	mark[x + 1] = true;
      	mark[x - 1] = true;
      	if(n >= 2) {
        	if(x > 2) {
            	mark[x - 2] = true;
            	a[n + 2] = x - 2;
            }
            else {
            	mark[x + 2] = true;
            	a[n - 2] = x + 2;
            }
        }
     	int cnt = 1;
      	for (int i = 1; i <= 2 * n - 1; i++) {
          	while(mark[cnt])
          		cnt++;
      		if(!a[i]) {
            	a[i] = cnt;
            	mark[cnt] = true;
            }
        }
    }
	if(x != 1 && x != 2 * n - 1)
    	for (int i = 1; i <= 2 * n - 1; i++)
        	cout << a[i] << endl;
 	return 0;
} 