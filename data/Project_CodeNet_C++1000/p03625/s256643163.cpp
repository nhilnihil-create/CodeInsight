#include <bits/stdc++.h>
 
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define ll long long
#define INF 999999999
#define MOD 1000000007
 
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
 
int iy[]={0, 0, 1, -1};
int ix[]={1, -1, 0, 0};
 
int n;
ll ma, mb;
ll a;
set<ll> S;
 
int main(){
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a;
		if(S.count(a)){
			S.erase(a);
			if(a > ma){
				mb = ma;
				ma = a;
			}else if(a > mb){
				mb = a;
			}
		}else{
			S.insert(a);
		}
	}
	cout <<  ma * mb << endl;
	return 0;
}