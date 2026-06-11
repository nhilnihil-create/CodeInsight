#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define INF 800000000
#define MAX 1000

int main(){
  int K,T;
  cin>>K>>T;
  vector<int> a(T);
  for(int i=0;i<T;i++){
    cin>>a.at(i);
  }
  sort(a.begin(),a.end());

  int b=a.at(T-1);
  if(b<=K/2){
    cout<<0<<endl;
  }else{
    cout<<K-2*(K-b)-1<<endl;
  }
}
