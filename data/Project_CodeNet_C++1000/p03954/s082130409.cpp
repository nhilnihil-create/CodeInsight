#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
  int n;
  cin>>n;
  int a[200000];
  for(int i=1; i<=2*n-1; i++){
    cin>>a[i];
  }
  int x1=1, x2=2*n-1;
  while(x1!=x2){
    int x=(x1+x2+1)/2;
    bool b[200000];
    for(int i=1; i<=2*n-1; i++){
      b[i]=(a[i]>=x);
    }
    if(b[n] && (b[n-1] || b[n+1])){
      x1=x;
      continue;
    }
    if(!b[n] && (!b[n-1] || !b[n+1])){
      x2=x-1;
      continue;
    }
    int l=-1, r;
    for(int i=1; i<=2*n-2; i++){
      if(l<0 && b[i] && !b[i+1]){
        l=i;
      }
      if(l>0 && b[i]==b[i+1]){
        if(b[i]) r=i;
        else r=i-1;
        if(r>=n) break;
        l=-1;
      }
    }
    if(l==1 && r==2*n-1){
      x1=x;
      continue;
    }
    bool ok;
    int m=(l+r)/2;
    if(m==n){
      ok=(b[r+1] || b[l-1]);
    }else if(m<n){
      ok=b[r+1];
    }else{
      ok=b[l-1];
    }
    if(ok) x1=x;
    else x2=x-1;
  }
  cout<<x1<<endl;
	return 0;
}