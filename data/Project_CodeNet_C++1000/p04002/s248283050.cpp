#include<iostream>
#include<map>
using namespace std;
long h,w,a,b,c,d,D[10]={0,1,-1,0,-1,-1,1,1},cnt[10],i,j;
map<pair<long,long>,long>m;
main()
{
	cin>>h>>w>>a;
	for(*cnt=(h-2)*(w-2);cin>>a>>b;i++)
		for(j=0;j<9;)
			if((c=a+D[j])>1&(d=b+D[++j])>1&c<h&d<w)cnt[c=m[make_pair(c,d)]++]--,cnt[c+1]++;
	for(i=0;i<10;i++)cout<<cnt[i]<<endl;
}