#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int maxn=100000+10;
int a[maxn];
int i,j,k,l,t,n,m;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
bool solve(){
	int i;
	fo(i,1,n)
		if (a[i]%2==1){
			/*if (a[i]==1){
				if (n%2==0) return 1;
				else return 0;
			}*/
			if (a[i]==1) return 0;
			a[i]--;
			break;
		}
	int d=a[1];
	fo(i,2,n) d=gcd(d,a[i]);
	fo(i,1,n) a[i]/=d;
	int t=0,l=0;
	fo(i,1,n)
		if (a[i]%2==0) t^=1;else l++;
	if (!t&&l==1) return solve()^1;
	else if (t) return 0;
	else return 1;
}
int main(){
	scanf("%d",&n);
	fo(i,1,n){
		scanf("%d",&a[i]);
		k=a[i];
		if (k%2==0) t^=1;else l++;
	}
	if (!t&&l==1){
		if (solve()) printf("First\n");else printf("Second\n");
		return 0;
	}
	if (t) printf("First\n");else printf("Second\n");
}