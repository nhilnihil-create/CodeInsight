#include <iostream>
 
using namespace std;
 
int main(){
  int N, A, B, c=0, b=0;
  cin >> N >> A >> B;
  string S;
  cin >> S;

  for (int i = 0; i < N; i++){
    if(S[i]=='a'){
      if ((A + B) > c){
        printf("Yes\n");
        c++;
      }else{
        printf("No\n");
      }
    }else if(S[i]=='b'){
      if (((A + B) > c) && (B > b)){
        printf("Yes\n");
        c++;
        b++;
      }else{
        printf("No\n");
      }
    }else{
      printf("No\n");
    }
  }

}
