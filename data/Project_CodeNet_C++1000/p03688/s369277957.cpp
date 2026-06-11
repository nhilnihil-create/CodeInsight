#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> as(n);
  for(Int i=0;i<n;i++) cin>>as[i];

  sort(as.begin(),as.end());
  Int p=as.front(),q=as.back();
  if(p==q){
    if(p==n-1) drop("Yes");
    if(p<=(n/2)) drop("Yes");
    drop("No");
  }

  if(p+1!=q) drop("No");

  Int x=count(as.begin(),as.end(),p);
  if(x+1>q) drop("No");
  if(x+(n-x)/2<q) drop("No");
  drop("Yes");
  return 0;
}
