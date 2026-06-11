#include<bits/stdc++.h>
#define N 1010
using namespace std;
int n,m;
int a[N];
vector<int> s,w;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d",&a[i]);
		if(a[i]&1) s.push_back(a[i]);
		else w.push_back(a[i]);
	}
	if(s.size()>2) puts("Impossible");
	else if(m==1){
		if(s.size()){
			if(s[0]==1) printf("1\n1\n1\n");
			else printf("%d\n2\n%d %d\n",s[0],s[0]/2,s[0]-s[0]/2);
		}
		else printf("%d\n2\n%d %d\n",w[0],w[0]/2+1,w[0]-w[0]/2-1);
	}
	else if(s.size()==0){
		for(int i=0;i<m;i++) printf("%d ",a[i]);
		puts("");
		printf("%d\n",m);
		a[0]--;a[m-1]++;
		for(int i=0;i<m;i++) printf("%d ",a[i]);
		puts("");
	}
	else if(s.size()==1){
		printf("%d ",s[0]);
		for(int i=0;i<w.size();i++) printf("%d ",w[i]);
		puts("");
		printf("%d\n",m);
		printf("%d ",s[0]+1);
		w[w.size()-1]--;
		for(int i=0;i<w.size();i++) printf("%d ",w[i]);
		puts("");
	}
	else if(s.size()==2){
		printf("%d ",s[0]);
		for(int i=0;i<w.size();i++) printf("%d ",w[i]);
		printf("%d\n",s[1]);
		s[0]--,s[1]++;
		m-=(s[0]==0);
		printf("%d\n",m);
		if(s[0]) printf("%d ",s[0]);
		for(int i=0;i<w.size();i++) printf("%d ",w[i]);
		printf("%d\n",s[1]);
	}
	else while(1);
	return 0;
}