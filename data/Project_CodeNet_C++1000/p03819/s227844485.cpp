#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <math.h>
#include <bitset>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <cassert>
#define INF 2000000000
using namespace std;
int dx[5]={1,0,-1,0,0},dy[5]={0,1,0,-1,0};
long long gcd(long long a,long long b){if(a%b==0){return b;}else return gcd(b,a%b);}
long long lcm(long long a,long long b){if(a==0){return b;} return a/gcd(a,b)*b;}
#define MOD 1000000007
#define sym cout<<"---------"<<endl;
#define ll long long
#define mk make_pair
#define en endl
#define RE return 0
#define int ll
#define P pair<int,int>

#define MAX 300005

struct BIT{
	int bit[MAX];
	void init(){
		memset(bit, 0, sizeof(bit));
	}
	void add(int i,int x){
		i++;
		while(i<MAX){
			bit[i]+=x;
			i+=i&-i;
		}
		
	}
	int get(int i){
		i++;
		int ret=0;
		while(i>0){
			ret+=bit[i];
			i-=i&-i;
		}
		return ret;
	}
};

BIT bit;
int n,m;

signed main(){
	cin>>n>>m;
	vector<int> kaz[MAX];
	for(int i=0; i<n; i++){
		int a,b; cin>>a>>b;
		b++;
		kaz[b-a].push_back(a);
	}
	int kazuto=n;
	for(int i=1; i<=m; i++){
		int ans=kazuto;
		for(int j=i; j<=m; j+=i){
			ans+=bit.get(j);
		}	
		kazuto-=kaz[i].size();
		for(int j=0; j<kaz[i].size(); j++){
			int l=kaz[i][j];
			int r=l+i;
			bit.add(l, 1);
			bit.add(r, -1);
		}
		printf("%lld\n",ans);
	}
}

