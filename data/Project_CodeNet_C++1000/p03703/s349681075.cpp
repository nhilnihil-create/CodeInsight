#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 2e5+5;

ll A[N];

int pen[N];
void update(int ind,int add) {
   while(ind<N) {
      pen[ind] += add;
      ind += ind&(-ind);
   }
}
int query(int ind) {
   int ret = 0;
   while(ind>0) {
      ret += pen[ind];
      ind = ind&(ind-1);
   }
   return ret;
}

int f(vector<ll> &g,ll x) {
   int l = 0,r = g.size()-1,mid;
   while(l<r) {
      mid = (l+r+1)/2;
      if(g[mid]<=x) {
         l = mid;
      } else {
         r = mid-1;
      }
   }
   return l+1;
}

void solve() {
   int n,k;
   scanf("%d %d",&n,&k);
   map<ll,int> Hash;
   Hash[0] = 0;
   vector<ll> gg;
   gg.push_back(0);
   ll inf = -1e18;
   gg.push_back(inf);
   for(int i=1;i<=n;++i) {
      scanf("%lld", &A[i]);
      A[i] = A[i]- k;
      A[i] = A[i] + A[i-1];
      Hash[A[i]];
      gg.push_back(A[i]);
   }
   int pos = 1;
   sort(gg.begin(),gg.end());
   ll ret = 0;
   int zero_ind = f(gg,0)+1;

   update(zero_ind,1);
   for(int i=1;i<=n;++i) {
      ll x= A[i];
      ll ind = f(gg,x)+1;
      ret += query(ind);
      update(ind,1);
   }
   printf("%lld\n", ret);
}

int main()
{
   //freopen("input.txt","r",stdin);
   solve();
}