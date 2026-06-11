#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)

int main(){
  string S,T;
  cin >> S;
  
  reverse(S.begin(), S.end());
  
  string dream = "maerd";
  string dreamer = "remaerd";
  string erase = "esare";
  string eraser = "resare";

  
  while(T != S){
    int countall = 0;
    int count1 = 0;
  for(int i = T.size(); i<T.size()+dream.size(); i++){
    if(S[i] != dream[i-T.size()]){
      count1++;
    }
  }
  if(count1 == 0) T += dream;
  if(count1) countall++;
  if(T == S) {
    cout << "YES" << endl;
    break;
  }

    
  
    int count3 = 0;
  for(int i = T.size(); i<T.size()+erase.size(); i++){
    if(S[i] != erase[i-T.size()]){
      count3++;
    }
  }
  if(count3 == 0) T += erase;
  if(count3) countall++;
  if(T == S){
    cout << "YES" << endl;
    break;
  }
  
    int count4 = 0;
  for(int i = T.size(); i<T.size()+eraser.size(); i++){
    if(S[i] != eraser[i-T.size()]){
      count4++;
    }
  }
  if(count4 == 0) T += eraser;
  if(count4) countall++;
  if(T == S){
    cout << "YES" << endl;
    break;
  }
    
    int count2 = 0;
  for(int i = T.size(); i<T.size()+dreamer.size(); i++){
    if(S[i] != dreamer[i-T.size()]){
      count2++;
    }
  }
  if(count2 == 0) T += dreamer;
  if(count2) countall++;
  if(T == S){
    cout << "YES" << endl;
    break;
  }
  
  if(countall >= 4){
    cout << "NO" << endl;
    break;
  }
  }
  return 0;
}
