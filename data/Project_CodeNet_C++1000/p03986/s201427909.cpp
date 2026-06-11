#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
	cout << fixed << setprecision(10);
	int cnt = 0;
	int s = 0, t = 0;
	string ss;
	cin >> ss;
	for(int i=0;i<ss.size();i++){
		if(ss[i]=='T'){
			if(s==0){
				cnt++;
			}
			else s--;
		}else s++;
	}
	//cout << cnt << endl;
	for(int i = ss.size()-1;i >=0 ; i--){
		if(ss[i]=='S'){
			if(t==0) cnt++;
			else t--;
		}else t++;		
	}
	cout << cnt << endl;
	return 0;
}