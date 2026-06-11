//love @Asibuto_Penta
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7;
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define pb push_back

ll N;
string S1,S2;
//red 0 blue 1 green 2 
ll dp1[55][5][5];
ll dp2[55][5];
ll which[55];
ll ans;
ll add(ll x,ll y){
	x=(x+y)%mod;
	return x;
}

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N>>S1>>S2;

ll i=0,in=0;
while(1){
	if(S1[i]!=S2[i]){
		which[in]=0; i+=2; in++;
	}else{
		which[in]=1; i++; in++;
	}
	if(i>=N) break;
}

if(which[0]==0){
	dp1[0][0][1]=1; dp1[0][1][0]=1;
	dp1[0][1][2]=1; dp1[0][2][1]=1;
	dp1[0][0][2]=1; dp1[0][2][0]=1;
}else{
	dp2[0][0]=1;
	dp2[0][1]=1;
	dp2[0][2]=1;
}

rep1(i,in){
	if(which[i]==0){
		if(which[i-1]==0){
			//add(dp1[i][c1][c2],dp1[i-1][c3][c4]);
			rep(c1,3){
				rep(c2,3){
					rep(c3,3){
						rep(c4,3){
							if(c1==c2) continue;
							if(c3==c4) continue;
							if(c1!=c3&&c2!=c4) dp1[i][c1][c2]=add(dp1[i][c1][c2],dp1[i-1][c3][c4]);
						}
					}
				}
			}
		}else{
			//add(dp1[i][c1][c2],dp2[i-1][c3])
			rep(c1,3){
				rep(c2,3){
					rep(c3,3){
						if(c1==c2) continue;
						if(c1!=c3&&c2!=c3) dp1[i][c1][c2]=add(dp1[i][c1][c2],dp2[i-1][c3]);
					}
				}
			}
		}
	}else{
		if(which[i-1]==0){
			//add(dp2[i][c1],dp1[i-1][c2][c3]);
			rep(c1,3){
				rep(c2,3){
					rep(c3,3){
						if(c2==c3) continue;
						if(c1!=c2&&c1!=c3) dp2[i][c1]=add(dp2[i][c1],dp1[i-1][c2][c3]);						
					}
				}
			}
		}else{
			//add(dp2[i][c1],dp2[i-1][c2])
			rep(c1,3){
				rep(c2,3){
					if(c1==c2) continue;
					dp2[i][c1]=add(dp2[i][c1],dp2[i-1][c2]);
				}
			}
		}
	}
}

if(which[in-1]==0){
	rep(c1,3){
		rep(c2,3){
			ans=add(ans,dp1[in-1][c1][c2]);
		}
	}
}else{
	rep(c1,3){
		ans=add(ans,dp2[in-1][c1]);
	}
}

cout<<ans<<endl;

}
	
