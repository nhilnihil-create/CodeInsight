#include <iostream>
#include <string>

using namespace std;

int main(){
  string S;
  cin >> S;

  if (S.size() < 5){
    printf("NO\n");
  }else{
    int p = S.size() - 1;
    while (p >= 4){
      if (S.substr(p - 4, 5) == "dream" || S.substr(p - 4, 5) == "erase"){
        p -= 5;
      }else if (S.substr(p - 5, 6) == "eraser"){
        p -= 6;
      }else if (S.substr(p - 6, 7) == "dreamer"){
        p -= 7;
      }else{
        break;
      }
    }

    if (p==-1){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
    
    
  }
  
}
