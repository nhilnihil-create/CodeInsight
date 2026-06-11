#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
#define INF 1e9
#define All(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;

int main() {
  string a,b;
  cin>>a>>b;
  int as=a.size(),bs=b.size();
  if(as>bs){
    cout<<"GREATER\n";
    return 0;
  }
  if(bs>as){
    cout<<"LESS\n";
    return 0;
  }
  if(a==b){
    cout<<"EQUAL\n";
    return 0;
  }

  for(int i=0;i<as;i++){
    if(a[i]>b[i]){
      cout<<"GREATER\n";
      return 0;
    }
    if(a[i]<b[i]){
      cout<<"LESS\n";
      return 0;
    }
  }

  return 0;
}
