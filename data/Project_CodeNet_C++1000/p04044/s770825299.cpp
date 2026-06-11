#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  cin>>A>>B;
  vector <string>vec(A);
  for(int i=0;i<A;i++){
    cin>>vec.at(i);
  }
  sort(vec.begin(),vec.end());
  for(int i=0;i<A;i++){
    cout<<vec.at(i);
  }
  
}
