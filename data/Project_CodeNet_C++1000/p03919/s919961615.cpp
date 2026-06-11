#include<bits/stdc++.h>
 
#define INF 1000000007
#define LINF 1000000000000000007
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> P;


int a,b;
string s[100][100];

int main(){
	cin >> a >> b;
	int ans1,ans2;
	for(int i = 0; i < a; i++){
		for(int j = 0; j < b; j++){
			cin >> s[i][j];
			if(s[i][j] == "snuke"){
				ans1 = i;
				ans2 = j;
			}
		}
	}
	
	cout << (char)('A'+ans2) << ans1+1 << endl;
	
	return 0;
}