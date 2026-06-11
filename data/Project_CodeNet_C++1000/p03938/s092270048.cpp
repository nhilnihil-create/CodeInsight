#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MAX 200003
#define MOD 1000000007
typedef int FLOW;

int main(){
  int N;
  cin>>N;
  vector<int> p(N);
  for(int i=0;i<N;i++){
    cin>>p.at(i);
  }
  vector<int> a(N),b(N);
  for(int i=0;i<N;i++){
    a.at(i)=30000*(i+1);
    b.at(i)=30000*(N-i);
  }
  for(int i=0;i<N;i++){
    a.at(p.at(i)-1)+=i;
    b.at(p.at(i)-1)+=i;
  }

  for(int i=0;i<N;i++){
    cout<<a.at(i)<<" ";
  }
  cout<<endl;
  for(int i=0;i<N;i++){
    cout<<b.at(i)<<" ";
  }
  cout<<endl;
}
