#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define kk 1000000007
int n,m,k,a,b,c,tmp,cc[300005];
vector<int > ee;
map<int ,int > mm;
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&cc[i]);
	for (int i=0;i<n;i++) ee.pb(cc[i]);
	sort(cc,cc+n);
	for (int i=0;i<n;i++){
		mm[cc[i]] = i;
	}
	for (int i=0;i<n;i++){
		if (mm[ee[i]]%2 != i%2) tmp++;
	}
	printf("%d\n",tmp/2);
	return 0;
}