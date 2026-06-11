#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<int,P> P1;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
#define mp1(a,b,c) P1(a,P(b,c))

const int INF=1000000001;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

ll gcd(ll x,ll y){
	if(y == 0)return x;
	return gcd(y,x%y);
}

int main(){
	static ll n;
	static ll a[100010];
	scanf("%lld",&n);
	rep(i,n)scanf("%lld",&a[i]);
	
	//if(n != 2){
		int cnt = 0;
		while(1){
			ll sum = 0;
			rep(i,n)sum += a[i];
			if(sum == n){
				if(cnt%2 == 0)puts("Second");
				else puts("First");
				return 0;
			}
			if((sum-n)%2 == 1){
				if(cnt%2 == 0)puts("First");
				else puts("Second");
				return 0;
			}
			int cnt_ = 0;
			rep(i,n){
				if(a[i]%2 == 1)cnt_ ++;
			}
			if(cnt_ > 1){
				if(cnt%2 == 0)puts("Second");
				else puts("First");
				return 0;
			}
			rep(i,n){
				if(a[i]%2 == 1){
					if(a[i] == 1){
						if(cnt%2 == 0)puts("Second");
						else puts("First");
						return 0;
					}
					else{
						a[i] -= 1;
						break;
					}
				}
			}
			ll g = 0;
			rep(i,n)g = gcd(g,a[i]);
			rep(i,n)a[i] /= g;
			cnt ++;
		}
	//}
}
	

