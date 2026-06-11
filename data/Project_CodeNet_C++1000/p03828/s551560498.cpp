#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <string.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define forn(i,a,b) for(int i=a;i<=b;i++)
#define INF 2147483647
#define LLINF 9223372036854775807
using namespace std;
//ָ��+1�����
long long cnt[1010];
void doo(int p){
	while(p){
		for(int i=2;i<=p;i++){
			if(p%i==0){
				p/=i;
				cnt[i]++;
				break;
			}
			if(i==p){
				cnt[p]++;
				p=0;
				break;
			}
		}
		if(p==1)break;
	}
}
int main(){
	int n;
	cin>>n;
	long long ans=1;
	for(int i=1;i<=n;i++){
		doo(i);
	}
	for(int i=1;i<=n;i++){
		ans*=(cnt[i]+1);
		ans%=1000000007;
	}
	cout<<ans<<endl;
	return 0;
}
