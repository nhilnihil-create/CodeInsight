#include <cstdio>
#include <map> 
using namespace std;
int a,n,am;
map<int,int>m;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a);
		m[a-1]++;
		m[a]++;
		m[a+1]++;
	}
	for(map<int,int>::iterator it=m.begin();it!=m.end();++it){
		am=(it->second>am?it->second:am);
	}
	printf("%d\n",am);
	return 0;
}
