# include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 1e5 + 21;
int n, m, cnt;
int a[MAXN], b[MAXN];
 
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        if(a[i] & 1) 
        	cnt++;
    }
  
    if(m == 1) {
    	if(a[1] == 1)
        	cout << 1 << '\n' << 1 << '\n' << 1 << '\n';
		else 
          cout << a[1] << '\n' << 2 << '\n' << a[1] - 1 << ' ' << 1 << '\n';
		return 0;
	}
    if(cnt > 2) 
      cout << "Impossible";
    else {
        int p = 1;
		for (int i = 1; i <= m; i++) {
			if((a[i] % 2) && p == 1) {
             	swap(a[i], a[1]);
              	p++;
            }
			else if((a[i] % 2) && p == 2) 
            	swap(a[i], a[m]);
		}
        for (int i = 1; i <= m; i++)
        	cout << a[i] << ' ';
        cout << '\n';
       	cout << m - (a[m] == 1) << '\n';
        cout << a[1] + 1 << ' ';
        for (int i = 2; i < m; i++)
        	cout << a[i] << ' ';
        if(a[m] > 1) 
          cout << a[m] - 1 << ' ';
    }
    return 0;
}
