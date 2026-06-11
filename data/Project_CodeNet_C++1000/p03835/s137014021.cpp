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
char g;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=0;i<=n;i++){
		for (int j=0;j<=n;j++){
			if (i+j <= k && k-i-j<=n) tmp++;
		}
	}
	printf("%d\n",tmp);
}