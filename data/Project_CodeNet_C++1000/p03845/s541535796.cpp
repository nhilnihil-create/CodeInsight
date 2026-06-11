#include <bits/stdc++.h>
#define rep(i , n) for (int i = 0; i < (int)(n); i++)
const int INF = 1<<29;
using namespace std;
using ll = long long;
int main(){
    int n , m , a[111] , b , c , sum = 0;
	cin >> n;
	for(int i=1;i<=n;i++){
	    cin >> a[i];
        sum += a[i];
    }
	cin >> m;
	while(m--){
	    cin >> b >> c;
        cout << sum - a[b] + c << endl; 
    }
	return 0;
}
