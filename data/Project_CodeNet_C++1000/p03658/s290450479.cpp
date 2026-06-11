#include <bits/stdc++.h>
using namespace std;
int n[1010];
int main(){
  int a,b;
  cin >> a >> b;
  for(int i = 0;i < a;i++){
    cin >> n[i];
  }
  
  sort(n,n+a,greater<int>());
  int length = 0;
  for(int i = 0;i < b;i++){
    length += n[i];
  }
  cout << length << endl;
}