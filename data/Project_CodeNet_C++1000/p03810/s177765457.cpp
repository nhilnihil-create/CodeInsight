#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int gcd(int x,int y) {
  return (x%y==0)?y:gcd(y,x%y);
}

int num[100005],n;

bool dfs() {
  bool ok=0;
  int s=0,now=0;
  for(int i=1;i<=n;i++) {
  	ok^=(!(num[i]&1));
  	if (num[i]&1) {
  		s++;now=num[i];
	  }
  }
  if (ok) return 1;
  else if (s>1||now==1) return 0;
  else {
  	for(int i=1;i<=n;i++)
  	  if (num[i]==now) num[i]--;
  	int d=num[1];
  	for(int i=2;i<=n;i++) d=gcd(d,num[i]);
  	for(int i=1;i<=n;i++) num[i]/=d;
  	return !dfs();
  }
}

int main() {
  scanf("%d",&n);
  if (n==1) {
  	puts("Second");
  	return 0;
  }
  for(int i=1;i<=n;i++) scanf("%d",&num[i]);
  puts((dfs())?"First":"Second");
  return 0;
}