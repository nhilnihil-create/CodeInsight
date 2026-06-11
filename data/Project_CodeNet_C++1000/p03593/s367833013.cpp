#include <iostream>
using namespace std;
int alp[26];
int main(){
  int h,w;cin>>h>>w;
  for(int i = 0; h > i; i++){
    for(int j = 0; w > j; j++){
      char z;cin>>z;
      alp[z-'a']++;
    }
  }
  int four = 0;
  int two = 0;
  int one = 0;
  for(int i = 0; 26 > i; i++){
    four += alp[i]/4;
    alp[i]%=4;
    two += alp[i]/2;
    alp[i]%=2;
    one += alp[i];
  }
  if((h/2)*(w/2) <= four){
    four -= (h/2)*(w/2);
    two += four*2;
  }else{
    cout << "No" << endl;
    return 0;
  }
  if((h%2) || (w%2)){
    if((h*w-((h/2)*(w/2))*4)/2 <= two){
      two -= (h*w-((h/2)*(w/2))*4)/2;
      one += two*2;
    }else{
      cout << "No" << endl;
      return 0;
    }
    if(h%2 && w%2){
      if(1 != one){
        cout << "No" << endl;
        return 0;
      }
    } 
  }
  cout << "Yes" << endl;
}
