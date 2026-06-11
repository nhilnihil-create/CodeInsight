#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
vector<int> a;
int n;
 
signed main() {
    cin >> n;
  	int suma = 0;
  	int ans = 0;
    for(int i = 0;i < n;i++){
        int j;cin >> j;
        if(j == 0){
          ans += suma/2;
          suma = 0;
          continue;
        }
        suma += j;
    }
   	ans += suma/2;
    cout << ans << endl;
	return 0;
}