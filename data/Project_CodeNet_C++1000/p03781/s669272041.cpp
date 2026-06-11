#include<bits/stdc++.h>
using namespace std;
int main(){
  int x;
  cin >> x;
  for(int i=0;i<=x;i++){
    if(i*(i+1)/2>=x){
      cout << i;
      return 0;
    }
  }
}
