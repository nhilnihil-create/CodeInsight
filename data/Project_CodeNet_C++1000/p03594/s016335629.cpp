#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
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

ll H,W,d,c[510][510];

int main(void){
	cin>>H>>W>>d;
	rep(i,H){
		rep(j,W){
			ll s=(i+j)/d, t=(H-1-i+j)/d;
			s%=2;
			t%=2; 
			if(s==0){
				if(t==0){
					printf("R");
				}else{
					printf("Y");
				}
			}else{
				if(t==0){
					printf("G");
				}else{
					printf("B");
				}
			}
		}
		printf("\n");
	}
	return 0;
}