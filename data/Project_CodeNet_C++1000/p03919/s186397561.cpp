#include <iostream>
#include <vector>
using namespace std;
int main(void){
  int m,n;
  cin >> m >> n;
  
  vector<vector<string>>word(m,vector<string>(n));
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      cin >> word[i][j];
    }
  }
  
  int a;
  char b;
  
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      if(word[i][j] == "snuke"){
        a = i + 1;
        b = char(j + 'A');
      }
    }
  }
  
  cout << b << a << endl;
  
  return 0;
}
