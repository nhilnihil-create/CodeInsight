#include <iostream>
#include <vector>
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  int hc = h, wc = w;
  vector<string> mat(h);
  for(int i=0; i<h; i++) cin >> mat[i];
  vector<int> vec(26, 0);
  int four=0, two=0, one=0;
  for(int i=0; i<100; i++){
    if(h!=0 && w!=0){
      if(min(h, w) >= 2){
        four++;
        if(w%2==1) two++;
        four += (w-2)/2;
        if(h%2==1) two++;
        four += (h-2)/2;
        w -= 2;
        h -= 2;
      }else{
        if(h!=1 || w!=1){
          if(h==1){
            if(w%2==1) one++;
            two += w/2;
          }else{
            if(h%2==1) one++;
            two += h/2;
          }
          h=0; w=0;
        }else if (h==1 && w==1){
          one++;
          h=0; w=0;
        }
      }
    }
  }
  for(int i=0; i<hc; i++){
    for(int j=0; j<wc; j++){
      vec[mat[i][j]-'a']++;
    }
  }
  for(int i=0; i<four; i++){
    bool isok = false;
    for(int j=0; j<26; j++){
      if(vec[j] >= 4){
        vec[j] -= 4;
        isok = true;
        break;
      }
    }
    if(!isok){
      cout << "No" << endl;
      return 0;
    }
  }
  for(int i=0; i<two; i++){
    bool isok = false;
    for(int j=0; j<26; j++){
      if(vec[j] >= 2){
        vec[j] -= 2;
        isok = true;
        break;
      }
    }
    if(!isok){
      cout << "No" << endl;
      return 0;
    }
  }
  for(int i=0; i<one; i++){
    bool isok = false;
    for(int j=0; j<26; j++){
      if(vec[j] >= 1){
        vec[j] -= 1;
        isok = true;
        break;
      }
    }
    if(!isok){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
  
  
