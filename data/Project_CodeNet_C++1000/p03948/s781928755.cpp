#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0;i < (n);i++)
#define P pair<int,int>
#define pb push_back
#define mk make_pair
using namespace std;
const int INF = 1 << 20;

typedef long long ll;




int main(){
  int n,t;
  cin >> n>> t;
  vector <int> a;
  vector <int> b;
  REP(i,n){
    int c;
    cin >> c;
    a.pb(c);
    
  }
  int mn =a[0],pos = 0;
  for(int i = 1;i < a.size();i++){
    b.pb(a[i]-mn);
    mn = min(mn,a[i]);
  }
  /*
  REP(i,b.size())
  cout << b[i] << endl;*/
  sort(b.begin(),b.end(), greater <int>() );
  int mx = b[0],num = 0;
  REP(i,b.size()){
    if(b[i] == mx)
      num++;
    else
      break;
  }
  cout << num << endl;
  
  return 0;
}
