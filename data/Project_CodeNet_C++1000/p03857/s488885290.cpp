#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define kk 1000000007
int l,n,m,k,a,b,c,tmp,cc[300005],u,v,gp1[300005],gp2[300005],an1[300005],an2[300005],an3[300005];
vector<int > ee;
map<pair<int ,int > ,int > mm;
int find1(int x){
	return gp1[x] == x? x : gp1[x] = find1(gp1[x]); 
}
int find2(int x){
	return gp2[x] == x? x : gp2[x] = find2(gp2[x]); 
}
char g;
int main(){
	scanf("%d%d%d",&n,&k,&l);
	for (int i=1;i<=n;i++) gp1[i] = i;
	for (int i=1;i<=n;i++) gp2[i] = i;	
	
	for (int i=0;i<k;i++){
		scanf("%d%d",&u,&v);
		gp1[find1(gp1[u])] = find1(gp1[v]);
	}
	
	for (int i=0;i<l;i++){
		scanf("%d%d",&u,&v);
		gp2[find2(gp2[u])] = find2(gp2[v]);
	}
	for (int i=1;i<=n;i++){
		if (!an1[find1(gp1[i])]) an1[find1(gp1[i])] = ++tmp;
		if (!an2[find2(gp2[i])]) an2[find2(gp2[i])] = ++tmp;		
	}
	for (int i=1;i<=n;i++){
		u = find1(gp1[i]);
		v = find2(gp2[i]);
		mm[mp(an1[u],an2[v])] ++;
	}
	for (int i=1;i<=n;i++){
		u = find1(gp1[i]);
		v = find2(gp2[i]);	
		an3[i] = mm[mp(an1[u],an2[v])];	
	}	
	for (int i=1;i<=n;i++) printf(i==n?"%d\n":"%d ",an3[i]);
}