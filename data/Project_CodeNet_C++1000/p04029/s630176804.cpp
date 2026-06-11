#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(void){
   int N;
   cin >> N;
   int ans = 0;
   for(int i=1;i<=N;i++){
       ans += i;
   }
   cout << ans << endl;
}
