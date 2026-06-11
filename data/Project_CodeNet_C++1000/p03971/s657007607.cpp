#include <bits/stdc++.h>

using namespace std;
 
int main() {
  int n,a,b;
  cin >> n >> a >> b;

  string s;
  cin >> s;
  int size = s.size();
  int foreign_rank = 1;
  int count = 0;
  for(int i=0;i<size;i++){
    if(s[i]=='a'){
      if(count < a+b){
        count++;
        printf("Yes\n");
      }else{
        printf("No\n");
      }
    }else if(s[i]=='b'){
      if(count < a+b && foreign_rank <= b){
        count++;
        printf("Yes\n");
      }else{
        printf("No\n");
      }
      foreign_rank++;
    }else{
      printf("No\n");
    }


  }
}