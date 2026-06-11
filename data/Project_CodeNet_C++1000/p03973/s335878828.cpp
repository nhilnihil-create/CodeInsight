#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;

/*
AC
*/

int main(void){
	ll n,a[100010],ans=0,c=1;
	cin>>n;
	rep(i,n)cin>>a[i];
	rep(i,n){
		if(i==0){
			ans+=a[0]-1;
			c=2;
		}else{
			if(a[i]==c){//ちょうどなら値段cを上げざるを得ない
				c++;
				continue;
			}else if(a[i]<c){
				continue;
			}else{
				if(a[i]%c==0){
					a[i]-=c+1;
					ans++;
				}
				ans+=a[i]/c;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}