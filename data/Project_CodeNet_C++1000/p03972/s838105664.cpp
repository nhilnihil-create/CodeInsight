#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
signed main(){
  int w,h;cin>>w>>h;
  int res=0;
  vector<int> p(w);
  vector<int> q(h);
  rep(i,w){
    cin>>p[i];
    res+=p[i];
  }
  rep(i,h){
    cin>>q[i];
    res+=q[i];
  }
  sort(q.begin(),q.end());
  vector<int> q_sum(h,0);
  q_sum[0]=q[0];
  rep1(i,h-1)q_sum[i]=q_sum[i-1]+q[i];
  rep1(i,w){
    auto it=lower_bound(q.begin(),q.end(),p[i-1]);
    int index=it-q.begin();
    if(index==0){
      res+=h*p[i-1];
      continue;
    }
    res+=q_sum[index-1];
    res+=(h-index)*p[i-1];
    //cout<<"res="<<res<<endl;
    //printf("%lld\n",index);
    /*rep1(j,h){
      //res+=min(p[i-1],q[j-1]);
      //printf("(%lld,%lld)=%lld\n",i,j,min(p[i-1],q[j-1]));
    }*/
  }
  rep(i,h){
    //printf("q[%lld]=%lld\n",i,q_sum[i]);
  }
  cout<<res<<endl;
  return 0;
}
