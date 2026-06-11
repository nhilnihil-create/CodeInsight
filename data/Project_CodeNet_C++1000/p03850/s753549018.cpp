#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#define INF 10000000000000000LL
using namespace std;

int main()
{
	int n;
  scanf("%d", &n);
  long long int a[100001];
  long long int sum[100001];
  sum[0]=0;
  vector<int> minus;
  for(int i=1; i<=n; i++){
    if(i<=n-1){
      char op;
      scanf("%lld ", &a[i]);
      sum[i]=sum[i-1]+a[i];
      scanf("%c ", &op);
      if(op=='-'){
        minus.push_back(i);
      }
    }else{
      scanf("%lld", &a[i]);
      sum[i]=sum[i-1]+a[i];
    }
  }
  long long int ans=-INF, sum1=sum[n];
  
  int m=minus.size();
  if(m==0){
    printf("%lld\n", sum[n]);
    return 0;
  }
  if(m==1){
    printf("%lld\n", sum[n]-2*a[minus[0]+1]);
    return 0;
  }
  for(int i=0; i<m; i++){
    if(i<m-1){
      long long int s=sum1-2*(sum[minus[i+1]]-sum[minus[i]]);
      if(ans<s) ans=s;
      sum1-=2*a[minus[i]+1];
    }else{
      sum1-=2*a[minus[i]+1];
      if(ans<sum1) ans=sum1;
    }
  }
  printf("%lld\n", ans);
	return 0;
}
