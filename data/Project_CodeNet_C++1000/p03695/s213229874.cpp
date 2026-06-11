#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX;
#define INFL LLONG_MAX;
typedef long long ll;
using namespace std;

int main(){
  int n; cin >> n;
  vector<int> a(n);
  vector<int> rate(9);
  rep(i,n){
    cin >> a.at(i);
    if(a.at(i)>=3200) rate.at(8)++;
    else rate.at(a.at(i)/400)++;
  }

  int Min=0,Max=0,no=0;

  rep(i,8){
    if(rate.at(i)>0) Min++;
    else if(rate.at(i)==0) no++;
  }

  if(Min==0){
    Min=1;
    Max=rate.at(8);
  }else{
    Max=Min+rate.at(8);
  }

  cout << Min << " " << Max <<endl;
}
