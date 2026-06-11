#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int H,W,h,w;cin >> H >> W >> h >> w;
	if(H%h==0 && W%w==0) cout << "No" << endl;
	else if(h<=2 || w<=2){
		cout << "Yes" << endl;
		rep(i,H){
			rep(j,W){
				if((i+1)%h==0 && (j+1)%w==0){
					if(j!=0) cout << " " << -(h*w-1)*H*W;
					else cout << -(h*w-1)*H*W;
				}
				else{
					if(j!=0) cout << " " << H*W-1;
					else cout << H*W-1;
				}
			}
			cout << endl;
		}
	}
	else{
		cout << "Yes" << endl;
		rep(i,H){
			rep(j,W){
				if((i+1)%h==0 && (j+1)%w==0){
					if(j!=0) cout << " " << -h*w;
					else cout << -h*w;
				}
				else{
					if(j!=0) cout << " " << 1;
					else cout << 1;
				}
			}
			cout << endl;
		}
	}
}
