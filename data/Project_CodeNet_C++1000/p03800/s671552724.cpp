#include <bits/stdc++.h>
using namespace std;
#define ALL(A) (A).begin(),(A).end()
#define ll long long
const ll mod = 1e9+7;
const ll INF = 2*1e18;
const int inf = 1e9+7;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	string s;
	cin >> s;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			vector<int> res;
			res.push_back(i);
			res.push_back(j);
			for(int k=1;k<N;k++){
				if(s[k]=='o')res.push_back(res[k-1]^res[k]);
				else res.push_back((res[k-1]+1^res[k])%2);
			}
			bool ok = 0;
			if(res[N]==res[0]){
				if(s[0]=='o'){
					if(res[0]==0){
						if(res[1]==res[N-1])ok=1;
					}else{
						if(res[1]!=res[N-1])ok=1;
					}
				}else{
					if(res[0]==0){
						if(res[1]!=res[N-1])ok=1;
					}else{
						if(res[1]==res[N-1])ok=1;
					}
				}
			}
			if(ok){
				for(int a=0;a<N;a++){
					if(res[a]==0)cout << "S";
					else cout << "W";
				}
				cout << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
}