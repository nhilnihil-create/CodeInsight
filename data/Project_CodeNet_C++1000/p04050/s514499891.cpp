#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n,m;
vector<int> s1,s2,s;

int main(){
	scanf("%d%d",&n,&m);
	int c0=0;
	for(int i=1;i<=m;i++){
		int t;
		scanf("%d",&t);
		if(t&1) s2.push_back(t);
		else s1.push_back(t);
	}
	if(s2.size()>2){
		puts("Impossible");
		return 0;
	}
	if(!s2.empty()){
		s.push_back(s2.back());
		s2.pop_back();
	}
	while(!s1.empty()){
		s.push_back(s1.back());
		s1.pop_back();
	}
	if(!s2.empty()){
		s.push_back(s2.back());
		s2.pop_back();
	}
	for(int i=0;i<s.size();i++) printf("%d ",s[i]);
	if(s.size()==1){
		if(s[0]==1){
			printf("\n1\n1");
			return 0;
		}
		printf("\n2\n%d %d\n",s[0]-1,1);
		return 0;
	}
	printf("\n%d\n",s[0]==1?s.size()-1:s.size());
	if(s[0]!=1) printf("%d ",s[0]-1);
	for(int i=1;i<s.size()-1;i++) printf("%d ",s[i]);
	if(s.size()>1) printf("%d\n",s.back()+1);
}
