#include<bits/stdc++.h>

#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ALL(a) (a).begin(),(a).end()
#define Yes(hoge) cout<<((hoge)?"Yes":"No")<<endl;
#define YES(hoge) cout<<((hoge)?"YES":"NO")<<endl;
using namespace std;
int main(){
  int n;cin>>n;
  vector<pair<int,int> >x(n);
  vector<int>num(n);
  bool used[n]={};
  vector<int>ans;
  ll sum=0;
  for(int i=0;i<n;i++){
    int a;cin>>a;
    x[i]=mp(a,i);
    num[i]=i;
    sum+=i;
  }
  sort(ALL(x));
  bool flag=true;
  for(int i=0;i<n;i++){
    //cout<<sum<<endl;
    //cout<<x[i].F<<" "<<i<<" "<<x[i].S<<endl;
    if((sum+ans.size())>=(x[i].F-1)){
      int cnt=i;
      int del=(x[i].F-ans.size()-1);
      //cout<<del<<endl;
      // cout<<x[cnt].S<<endl;
      while(del>0){
	if(num[x[cnt].S]>0){
	  num[x[cnt].S]--;
	  del--;
	  sum--;
	  ans.pb(x[cnt].S+1);
	}else{
	  cnt++;
	}
	if(cnt==n)break;
      }
      cnt=0;
      while(del>0){
	if(num[x[cnt].S]>0){
	  num[x[cnt].S]--;
	  del--;
	  sum--;
	  ans.pb(x[cnt].S+1);
	}else{
	  cnt++;
	}
	if(cnt==i){flag=false;}
      }
      if(del==0&&num[x[i].S]>0)flag=false;
      ans.pb(x[i].S+1);
      sum+=n-x[i].S-1;
      num[x[i].S]=n-x[i].S-1;
    }else{
      flag=false;
    }
    /*
    for(int ii=0;ii<ans.size();ii++){
      cout<<ans[ii];
      if(ii!=ans.size()-1)
	cout<<" ";
    }
    cout<<endl;*/
    //  cout<<flag<<endl;
  }
   for(int i=0;i<n;i++){
    int aaa=num[i];
    for(int j=0;j<aaa;j++){
      ans.pb(i+1);
    }
    }
  if(flag){
    cout<<"Yes"<<endl;
    for(int i=0;i<ans.size();i++){
      cout<<ans[i];
      if(i!=ans.size()-1)
	cout<<" ";
    }
    cout<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}
