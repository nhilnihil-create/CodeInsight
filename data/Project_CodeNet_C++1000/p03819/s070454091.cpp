#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+5;

int sum[N],add[N];

int pen[N];

void update(int ind,int add) {
   while(ind<N) {
      pen[ind] += add;
      ind += ind&(-ind);
   }
}
int query(int ind) {
   int ret= 0;
   while(ind>0) {
      ret += pen[ind];
      ind = ind&(ind-1);
   }
   return ret;
}

vector<pair<pair<int,int>,int> > input[N];

void solve() {
   int n,m;
   scanf("%d%d",&n,&m);
   for(int i=0;i<n;++i) {
      int l,r;
      scanf("%d%d",&l,&r);
      int len = r-l+1;
      sum[1] += 1;
      sum[len+1] -= 1;
      if(len+1<=r) {
         input[len+1].push_back(make_pair(make_pair(l,r),1));
         input[r+1].push_back(make_pair(make_pair(l,r),-1));
      }
   }
   int d,i,l,r,pos,ret;
   for(d=1;d<=m;++d) {
      sum[d] = sum[d-1] + sum[d];
      for(i=0;i<input[d].size();++i) {
         l = input[d][i].first.first;
         r = input[d][i].first.second;
         pos = input[d][i].second;
         update(l,pos);
         update(r+1,-pos);
      }
      ret = sum[d];
      for(i = d;i<=m;i+=d) {
         ret += query(i);
      }
      printf("%d\n", ret);
   }
}
int main() {
   //freopen("input.txt","r",stdin);
   solve();
}