#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define INF 800000000
#define MAX 1000

int main(){
  int N;
  cin>>N;
  vector<int> a(N);
  vector<pair<int,int>> p(N);
  for(int i=0;i<N;i++){
    cin>>a.at(i);
    p.at(i).first=a.at(i);
    p.at(i).second=i+1;
  }
  sort(p.begin(),p.end());
  int ans=0;
  for(int i=0;i<N;i++){
    if(a.at(p.at(i).first-1)==p.at(i).second){
      ans++;
    }
  }
  cout<<ans/2<<endl;
}
