#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <queue>
#include <string>
#define pb push_back
#define mod 1000000007
#define all(x) x.begin(),x.end()
#define inf (int)(1e9)
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;

int main(void){
  int n,x;
  cin>>n;
  int tmp=0;
  vector<int> p;
  p.pb(-1);
  for(int i=1;i<=n;i++){
    cin>>x;
    p.pb(x);
  }
  for(int i=1;i<=n;i++){
    if(i==p[i]){
      if(i+1==p[i+1]) i++;
      tmp++;
    }
  }
  cout<<tmp<<endl;
  return 0;
}
