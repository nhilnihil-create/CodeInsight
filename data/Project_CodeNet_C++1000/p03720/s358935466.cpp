#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N, M;
  cin >> N >> M;
  
int number =0;
  
  vector<int> vec(M*2);
  
 
   for(int j=1; j<N+1; j++){
     for(int i=0; i<M*2; i++){
    cin >> vec. at(i);
    if(vec. at(i) ==j)
      number++;
    }
    cout << number << endl;  
     number = 0;
  }
}

