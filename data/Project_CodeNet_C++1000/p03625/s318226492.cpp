#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define fo(a,b) for(int a=0;a<b;a++)
#define Sort(a) sort(a.begin(),a.end())
#define rev(a) reverse(a.begin(),a.end())
#define fi first
#define se second
#define sz size()
#define bgn begin()
#define en end()
#define pb push_back
#define pp() pop_back()
#define V vector
#define P pair
#define yuko(a) setprecision(a)
#define uni(a) a.erase(unique(a.begin(),a.end()),a.end())
#define Q queue
#define pri priority_queue
#define Pri priority_queue<int,vector<int>,greater<int>>
#define PriP priority_queue<P<int,int>,vector<P<int,int>>,greater<P<int,int>>>
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
#define all(a)  (a).begin(),(a).end()
#define elif else if


signed main(){
  int n;
  cin>>n;
  V<int> a(n);
  fo(i,n){
    cin>>a[i];
  }
  Sort(a);
  rev(a);
  V<int> g=a;
  uni(g);
  V<P<int,int>> d(g.sz);
  int j=0;
  for(int i=0; i<n; i=i){
    int b=a[i];
    int c=0;
    d[j].fi=b;
    while(i<n){
      if(a[i]==b)
        c++;
      else
        break;
      i++;
    }
    d[j].se=c;
    j++;
  }
  int e=0,f=0;
  fo(i,g.sz){
    if(d[i].se>=2&&e==0){
      d[i].se-=2;
      e=d[i].fi;
    }
    if(d[i].se>=2&&e>0){
      f=d[i].fi;
      break;
    }
  }
  cout<<e*f<<endl;
}