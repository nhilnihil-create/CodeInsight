#include <iostream>
using namespace std;
int main(void){
 int N, s;
  s = 0;
 cin >> N;
  
 for (int i = 1; i <= N; i++){
   s = s + i;
 }
   cout << s << endl;
return 0;
}
