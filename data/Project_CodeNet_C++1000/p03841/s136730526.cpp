#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
const int mod=1000000007;
const int mod1=998244353;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;cin >> n;
	vector<pii> x(n);
	rep(i,n){
		cin >> x.at(i).first;
		x.at(i).second=i;
	}
	vector<int> ans(n*n),a(n),b(n);
	vector<bool> c(n);
	rep(i,n){
		a.at(i)=n-1-i;
		b.at(i)=n-1;
	}
	rep(i,n) ans.at(x.at(i).first-1)=i+1;
	sort(x.rbegin(),x.rend());
	int j=0,k=0;
	bool flg=true,flg1=false;
	for(int i=n*n-1;i>=0;--i){
		if(ans.at(i)){
			c.at(ans.at(i)-1)=true;
			if(a.at(ans.at(i)-1)>0){
				flg=false;
				break;
			}
			continue;
		}
		if(flg1){
			bool flg2=true;
			rep(l,n){
				if(c.at(l) && b.at(l)){
					k=l;
					flg2=false;
					break;
				}
			}
			if(flg2){
				flg=false;
				break;
			}
			ans.at(i)=k+1;
			b.at(k)--;
		}
		else{
			while(a.at(x.at(j).second)==0){
				j++;
				if(j==n) break;
			}
			if(j==n){
				flg1=true;
				bool flg2=true;
				rep(l,n){
					if(c.at(l) && b.at(l)){
						k=l;
						flg2=false;
						break;
					}
				}
				if(flg2){
					flg=false;
					break;
				}
				ans.at(i)=k+1;
				b.at(k)--;
				continue;
			}
			ans.at(i)=x.at(j).second+1;
			a.at(x.at(j).second)--;
			b.at(x.at(j).second)--;
		}
	}
	if(flg){
		cout << "Yes" << endl;
		rep(i,n*n){
			if(i==n*n-1) cout << ans.at(i) << endl;
			else cout << ans.at(i) << " ";
		}
	}
	else cout << "No" << endl;
}