#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <bitset>
using namespace std;
typedef long long ll;
const int maxn = 100005;

string s;
int main() {
#ifdef suiyuan2009
  freopen("in.cpp","r",stdin);
#endif // suiyuan2009
  ll ret=0;
  while(1) {
    int st=(ret==0LL);
    int l=st,r=9,ans=-1;
    while(l<=r) {
      int m=(l+r)>>1;
      printf("? %lld\n",ret*10+m);
      fflush(stdout);
      cin>>s;
      if(s[0]=='Y') {
        ans=m;
        l=m+1;
      } else r=m-1;
    }
    if(ans!=9) {
      ret=ret*10+ans;
    } else {
      printf("? %lld\n",ret*100+st*10);
      fflush(stdout);
      cin>>s;
      if(s[0]=='N') {
        int l=st+1,r=9,ans=-1;
        while(l<=r) {
          int m=(l+r)>>1;
          printf("? %lld\n",ret*100+m*10);
          fflush(stdout);
          cin>>s;
          if(s[0]=='Y') {
            ans=m;
            r=m-1;
          } else l=m+1;
        }
        printf("! %lld\n",ret*10+ans);
        fflush(stdout);
        exit(0);
      } else {
        ll tmp=ret*10+st;
        while(tmp<=100000000000000000L)tmp*=10;
        printf("? %lld\n",tmp);
        fflush(stdout);
        cin>>s;
        if(s[0]=='N') {
          ret=ret*10+9;
        } else {
          printf("! %lld\n",ret*10+st);
          fflush(stdout);
          exit(0);
        }
      }
    }
  }
  return 0;
}
