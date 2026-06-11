#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n; cin >> n;
  vector<int> A;
  int nak=0;
  for(int i=0;i<n;i++){int a;cin >> a;A.push_back(--a);}
  for(int i=0;i<n;i++){if(A[A[i]]==i) nak++;}
  cout << nak/2 << endl;
}