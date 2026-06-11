#include <iostream>
#include <string>

using namespace std;

int main(){
  string S;
  cin >> S;

  char c;
  int flg = 0;
  for (int i = 0; i < 26; i++){
    c = 'a' + i;
    if (S.find(c) == string::npos) break; 
    if (i==25) flg=1;
  }

  if (flg == 1){
    printf("None\n");
  }else{
    printf("%c\n", c);
  }
  
}
