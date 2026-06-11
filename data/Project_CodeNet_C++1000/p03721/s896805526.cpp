#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define rep(i,n) for (int i=0;i<n;i++)

int main(){
  int N; int64_t K; cin >> N >> K;

  vector<pair<int, int>> ab;
  int a, b;
  rep(i,N){
    cin >> a >> b;
    ab.push_back(make_pair(a,b));
  } 
  sort(ab.begin(),ab.end());
  //for (auto p:ab) cout << p.first << p.second << endl;
  
  int64_t sum=0;

  rep(i,N){
    sum += ab.at(i).second;
    if (sum>=K){
      cout << ab.at(i).first << endl;
      break;
    } 
  }

  
}

 