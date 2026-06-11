#include <iostream>

using namespace std;

int main(){
  string w;
  int a[26];
  cin >> w;
  for (int i = 0; i < 26; i++){
    a[i] = 0;
  }

  for (int i = 0; i < w.size(); i++){
    int n = w[i] - 'a';
    a[n]++;
  }

  int flg = 0;
  for (int i = 0; i < 26; i++){
    if (a[i]%2 != 0) flg = 1;
  }

  if (flg == 0){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  
}
