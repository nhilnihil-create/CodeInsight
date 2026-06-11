#include <iostream>
#include <string>
using namespace std;

int main(){
  int N, A, B;
  string s;
  cin >> N >> A >> B >> s;
  int count_all = 0, count_b = 0;
  for (int i = 0; i < N; i++){
    if (s[i] == 'c'){
      cout << "No" << endl;
    }
    if (s[i] == 'b'){
      count_b++;
      count_all++;
      if(count_all <= A + B && count_b <= B) cout << "Yes" << endl;
      else{
      cout<< "No" << endl;
      count_all--;
      }
    }
    if (s[i] == 'a'){
      count_all++;
      if(count_all <= A + B) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
}