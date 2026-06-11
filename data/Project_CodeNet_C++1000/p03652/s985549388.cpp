#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value!=0>::type
fill_v(U &u,const V... v){u=U(v...);}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value==0>::type
fill_v(U &u,const V... v){
  for(auto &e:u) fill_v<T>(e,v...);
}


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed main(){
  int n,m;
  cin>>n>>m;
  auto as=make_v<int>(n,m);

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin>>as[i][j],as[i][j]--;

  int ans=n;
  for(int t=0;t<m;t++){
    vector<int> cnt(m,0);
    for(int i=0;i<n;i++){
      int k=m;
      for(int j=m-1;j>=0;j--)
        if(~as[i][j]) k=as[i][j];
      cnt[k]++;
    }

    int p=max_element(cnt.begin(),cnt.end())-cnt.begin();
    chmin(ans,cnt[p]);

    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        if(as[i][j]==p) as[i][j]=-1;
  }

  cout<<ans<<endl;
  return 0;
}
