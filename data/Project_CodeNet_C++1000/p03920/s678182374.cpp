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

/*

*/

ll n,discard,largest;

int main(void){
	cin>>n;
	reg(i,1,n){
		if(i*(i+1)/2>=n){
			largest=i;
			discard=i*(i+1)/2-n;//取り除く数
			break;
		}
	}
	reg(i,1,largest){
		if(i!=discard)cout<<i<<endl;
	}
	return 0;
}