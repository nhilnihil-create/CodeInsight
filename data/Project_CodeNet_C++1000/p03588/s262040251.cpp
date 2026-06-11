#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
  
  int n;
  cin>>n;

    vector<int> A(n);
    vector<int> B(n);
    int maxwk=0;
    int index;
    for(int i=0;i<n;i++){
      cin>>A.at(i)>>B.at(i);
      if(A.at(i)>maxwk){
        maxwk=A.at(i);
        index=i;
      }
    }
  
  cout<<A.at(index)+B.at(index)<<endl;
  return 0;
}