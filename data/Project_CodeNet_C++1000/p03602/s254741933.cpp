/*
 * test.cpp
 *
 *
 *      Author: Fireworks
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
#include<cmath>
#include<bitset>
#include<set>
#include<iomanip>
#include<fstream>
#include<bitset>
#include<cstring>
#include<cstdlib>
#include<complex>
#include<list>
#include<sstream>

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,long long> il;
typedef pair<long long,long long> ll;
typedef pair<ll,int> lli;
typedef pair<long long,int> li;
typedef pair<double,double> dd;
typedef pair<ii,int> iii;
typedef pair<double,int> di;
long long mod = 1000000007LL;
long long base = 10000007;
long long large = 1000000000000000000LL;





int main(){
	int n;
	cin>>n;
	vector<vector<int> > g(n,vector<int>(n,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cin>>g[i][j];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(g[i][j]+g[j][k]<g[i][k]){
					cout<<-1<<endl;
					return 0;
				}
			}
		}
	}

	long long ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			bool flag = true;
			for(int k=0;k<n;k++){
				if(k==i||k==j) continue;
				if(g[i][j]==g[i][k]+g[k][j]) flag = false;
			}
			if(flag) ans+=1LL*g[i][j];
		}
	}
	cout<<ans/2<<endl;

	return 0;
}
