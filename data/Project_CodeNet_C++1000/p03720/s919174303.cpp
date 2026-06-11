#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  int a[55];
  int b[55];
  vector<int> c(55);
  for(int i=0;i<M;i++){
    cin >> a[i] >> b[i];
  }
  
  for(int i=0;i<N;i++){
    //c[i]=i+1;
    for(int j=0;j<M;j++){
    	if((i+1)==a[j]||(i+1)==b[j]){
          c.at(i)++;
        }
    }
  }
  for(int i=0;i<N;i++){
    cout << c.at(i) << endl;
  }
}

         
    
  
  