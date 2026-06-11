#include <bits/stdc++.h>

using namespace std;
 
int main() {
  int n;
  int m;
  int a;
  cin >> n;
  cin >> m;
  vector<int> vct(n);
  for(int i=0;i<2*m;i++){
    cin >>a;
    vct[a-1]++;
  }
  
  for(int i=0;i<n;i++){
        cout <<vct[i]<<endl;  
  }



  }     

