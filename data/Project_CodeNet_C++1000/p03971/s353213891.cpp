#include <iostream>
#include <string>
using namespace std;
int main(){
  int N,A,B;
  int count_a=0,count_b=0;
  string s;
  cin >> N >> A >> B;
  cin >> s;
  for(int i=0;i<N;i++){
    if(s[i] == 'a'){
      if(count_a + count_b < A+B){
        cout << "Yes" << endl;
        count_a++;
      }else{
        cout << "No" << endl;
      }
    }else if(s[i] == 'b'){
      if(count_a+count_b < A+B && count_b < B){
        cout << "Yes" << endl;
        count_b++;
      }else{
        cout << "No" << endl;
      }
    }else{
      cout << "No" << endl;
    }
  }
}