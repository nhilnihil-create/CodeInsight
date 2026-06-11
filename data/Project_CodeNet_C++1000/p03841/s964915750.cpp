#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#define MAXN 250010
using namespace std;

int n;
pair<int,int> a[MAXN];
stack<pair<int,int> > S;
int b[MAXN];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].first);
		a[i].second=i;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int cnt=1;
		int x=1;
		b[a[i].first]=a[i].second;
		while(x<a[i].first && cnt<a[i].second){
			if(!b[x]){
				b[x]=a[i].second;
				cnt++;
			}
			x++;
		}
		if(cnt<a[i].second){
			puts("No");
			return 0;
		}
		for(int j=1;j<=n-a[i].second;j++)
			S.push(make_pair(a[i].first,a[i].second));
	}
	for(int i=n*n;i>=1;i--)
		if(!b[i]){
			if(S.top().first>=i){
				puts("No");
				return 0;
			}
			b[i]=S.top().second;
			S.pop();
		}
	puts("Yes");
	for(int i=1;i<=n*n;i++) printf("%d ",b[i]);
}
