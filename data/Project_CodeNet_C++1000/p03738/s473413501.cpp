#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define read freopen("in.txt","r",stdin)
#define write freopen("out.txt","w",stdout)
#define mem(x,n) memset(x,n,sizeof(x))
#define all(x) x.begin(), x.end()
#define endl "\n"

int main()
{
	faster;
	
	string a,b;
	cin >> a >> b;
	int ans = 1;

	if(a.size() < b.size()){
		ans = 3;
	}else if(a.size() > b.size()) {
		ans = 2;
	}else {
		for(int i = 0; i < a.size(); i++){
			if(a[i] > b[i]){
				ans = 2;
				break;
			}else if(a[i] < b[i]){
				ans = 3;
				break;
			}
		}
	}

	if(ans == 1) cout << "EQUAL" << endl;
	else if(ans == 2) cout << "GREATER" << endl;
	else cout << "LESS" << endl;
	
	return 0;
}