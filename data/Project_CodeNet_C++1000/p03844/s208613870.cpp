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
	scanf("%d%c%c%d",&a,&g,&g,&b);
	if (g == '+') printf("%d\n",a+b);
	else printf("%d\n",a-b);
	return 0;
}