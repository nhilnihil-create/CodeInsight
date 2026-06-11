#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  set<int> S;
  for(int i=0;i<N;i++){
    int A;
    cin>>A;
    if(S.count(A))
      S.erase(A);
    else
      S.insert(A);
  }
  cout<<S.size()<<endl;
}
