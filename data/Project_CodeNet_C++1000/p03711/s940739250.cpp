#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int> v={0,1,0,2,0,2,0,0,2,0,2,0};
  int a,b;
  cin >> a >> b;
  if(v[a-1]==v[b-1]){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}