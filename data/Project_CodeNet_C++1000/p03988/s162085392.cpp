#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define dbg(x) cout<<#x<<":"<<x<<endl
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;

int main(){
  int n;
  cin>>n;
  int cnt[111]={};
  int ma=0;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    cnt[a]++;
    ma=max(a,ma);
  }

  if(n==2){
    if(cnt[1]==2)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
    return 0;
  }

  if(cnt[ma]<2){
    cout<<"Impossible"<<endl;
    return 0;
  }

  if(ma%2==0&&cnt[ma/2]!=1){
    cout<<"Impossible"<<endl;
    return 0;
  }

  if(ma%2&&cnt[ma/2+1]!=2){
    cout<<"Impossible"<<endl;
    return 0;
  }
  
  int sum=cnt[ma];
  int s;
  if(ma%2==0){
    sum++;
    s=ma/2+1;
  }else{
    sum+=2;
    s=ma/2+2;
  }
  
  for(int i=s;i<ma;i++){
    if(cnt[i]<2){
	 cout<<"Impossible"<<endl;
	 return 0;
    }
    sum+=cnt[i];
  }

  if(sum==n)cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
  
  return 0;
}
