#include <iostream>
#include <string>
using namespace std;
 
int main() {
  string s;
  cin >> s;
  int count = 0;
  int max = 0;
  for(int i = 0;i<s.size();i++){
    count=0;
    if(s[i] == 'A'){
        for(int j = s.size()-1;0<j;j--){
            if(s[j] == 'Z') {
                count = j - i+1;
                break; 
            }
        }
    }
    if(max < count) max = count;
  }
  cout << max << endl;
}