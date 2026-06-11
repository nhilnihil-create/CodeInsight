#include <bits/stdc++.h>
using namespace std;
 
int main(){
	string s;
    cin >> s;
    int N = s.size();
     vector<char> v(N);
    for(int i=0; i<N; i++){
    v.at(i) = s.at(i);
    }
    vector<char> vodd(N);
    for(int i=0; i<N; i++){
    vodd.at(i/2) = v.at(i);
    i++;
    }
  if(N%2 == 0){
    for(int i=0; i<N/2; i++){
    cout << vodd.at(i);
    }
  }
  if(N%2 == 1){
    for(int i=0; i<(N+1)/2; i++){
      cout << vodd.at(i);
    }
  
  }
 

  }  