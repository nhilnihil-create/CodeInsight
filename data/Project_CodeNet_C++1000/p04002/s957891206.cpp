#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
set<pair<int,int> > s1,s2;
int dx[8]={-1,-1,-1,0,0,1,1,1},dy[8]={-1,0,1,-1,1,-1,0,1};
int n,m,a,i,j;
long long ans[10];
bool in(int x,int y)
{
	return x<=n&&x>=1&&y<=m&&y>=1;
}
int main()
{
	cin>>n>>m>>a;
	for(i=1;i<=a;i++){
		int x,y;
		cin>>x>>y;
		s1.insert(make_pair(x,y));
		s2.insert(make_pair(x,y));
		for(j=0;j<8;j++){
			if(in(x+dx[j],y+dy[j])) s2.insert(make_pair(x+dx[j],y+dy[j]));
		}
	}
	set<pair<int,int> >::iterator it;
	for(it=s2.begin();it!=s2.end();it++){
		int x=(*it).first,y=(*it).second,cnt=0;
		if(s1.count(make_pair(x,y))) cnt++;
		for(j=0;j<8;j++){
			if(!in(x+dx[j],y+dy[j])){
				cnt=0;
				break;
			}
			if(s1.count(make_pair(x+dx[j],y+dy[j]))) cnt++;
		}
		ans[cnt]++;
	}
	long long tmp=0;
	for(i=1;i<=9;i++) tmp+=ans[i];
	cout<<1LL*(n-2)*(m-2)-tmp<<endl;
	for(i=1;i<=9;i++) cout<<ans[i]<<endl;
	return 0;
}
