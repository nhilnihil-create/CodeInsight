#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MAX 1000000
#define MOD 1000000007
#define INF 100000000000000

int main(){
  int N,M;
  cin>>N>>M;
  vector<int> a(M),b(M);
  for(int i=0;i<M;i++){
    cin>>a.at(i)>>b.at(i);
    a.at(i)--;
    b.at(i)--;
  }
  vector<int> count(N);
  for(int i=0;i<M;i++){
    count.at(a.at(i))++;
    count.at(b.at(i))++;
  }
  bool flag=true;
  for(int i=0;i<N;i++){
    if(count.at(i)%2==1){
      flag=false;
    }
  }
  if(flag){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}
