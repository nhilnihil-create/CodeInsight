#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}

//INSERT ABOVE HERE
signed main(){
  Int h,w,n,m;
  cin>>h>>w>>n>>m;
  if(h%n==0&&w%m==0) drop("No");

  cout<<"Yes"<<endl;
  for(Int i=0;i<h;i++){
    for(Int j=0;j<w;j++){
      if(j) cout<<" ";
      cout<<(i%n==n-1&&j%m==m-1?-1000*n*m+999:1000);
    }
    cout<<endl;
  }
  return 0;
}
