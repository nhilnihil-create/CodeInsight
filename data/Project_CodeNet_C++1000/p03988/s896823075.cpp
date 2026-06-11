#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int n;
map<int,int> m;

int mn=200,mx=0;
bool t=true;

int main(){
  cin >> n;
  int a;
  rep(i,0,n){
    cin >> a;
    mn = min(mn,a);
    mx = max(mx,a);
    m[a]++;
  }

  if(mx%2==0){
    if(mn!=mx/2)t=false;
    if(m[mn]!=1)t=false;
    rep(i,mn+1,mx+1){
      if(m[i]<2)t=false;
    }
  }else{
    if(mn!=(mx+1)/2)t=false;
    if(m[mn]!=2)t=false;
    rep(i,mn+1,mx+1){
      if(m[i]<2)t=false;
    }
  }

  if(t){
    cout << "Possible" << endl;
  }else{
    cout << "Impossible" << endl;
  }

  return 0;
}
