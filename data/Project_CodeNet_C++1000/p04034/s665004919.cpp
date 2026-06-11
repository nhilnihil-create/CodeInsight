#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int , int> ii;
typedef pair<ii , int> iii;
int n , m , a , b , isi[200000] , ans;
bool cek[200000];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		isi[i] = 1;
	}
	cek[1] = true;
	for(int i = 1 ; i <= m ; i++){
		cin >> a >> b;
		if(cek[a])cek[b] = true;
		if(isi[a] == 1)cek[a] = false;
		isi[b]++;
		isi[a]--;
	}
	ans = 0;
	for(int i = 1 ; i <= n ; i++){
		if(cek[i]){
			ans++;
		}
	}
	cout << ans << endl;
}