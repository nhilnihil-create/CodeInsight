#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,i,need = 0;string beh;stack<char> v;cin >> n >> beh;
  for(i=0;i<n;i++){
    if(beh[i]==')' && v.empty()) need++;
    else if(beh[i]==')') v.pop();
    else v.push(beh[i]);
  }
  cout << string(need,'(') << beh << string(v.size(),')') << "\n";
}