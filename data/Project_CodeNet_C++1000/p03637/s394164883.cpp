#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  ll n,a[100010];
  ll four=0,two=0,other=0;
  cin>>n;
  rep(i,n){
    cin>>a[i];
    if(a[i]%4==0&&a[i]>2){
      four++;
    }else if(a[i]%2==0){
      two++;
    }
  }

  if(four+two/2>=n/2){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}
