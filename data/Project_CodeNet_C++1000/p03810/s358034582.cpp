#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <iostream>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;


int gcd(int a,int b){
	if(b>a)return gcd(b,a);
	if(b==0)return a;
	return gcd(b,a%b);
}

int n;
int a[1000001];

void solve(int v){
	int cnt=0,cnt2=0;
	for(int i=0;i<n;i++){
		if(a[i]%2==0)cnt++;
		else cnt2++;
	}
	if(cnt%2==1){
		printf("%s\n",v%2==0?"First":"Second");
		return;
	}else{
		if(cnt2!=1){
			printf("%s\n",v%2==1?"First":"Second");
			return;
		}else{
			for(int i=0;i<n;i++){
				if(a[i]%2==1){
					if(a[i]==1){
						printf("%s\n",v%2==1?"First":"Second");
						return;
					}
					a[i]--;
				}
			}
			int gc=a[0];
			for(int i=1;i<n;i++){
				gc=gcd(gc,a[i]);
			}
			for(int i=0;i<n;i++){
				a[i]/=gc;
			}
			solve(v+1);
			return;
		}
	}
}

int main(void){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	if(n==1){
		printf("%s\n",a[0]==1?"Second":"First");
	}else{
		solve(0);
	}
	return 0;
}
