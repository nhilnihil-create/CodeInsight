#include <iostream>
#include <vector>
using namespace std;

int main(void){
   long long a,b;
   cin >> a >> b;
   if(a > 0){
       cout << "Positive" << endl;
   }else if(a == 0){
       cout << "Zero" << endl;
   }else{// a < 0
       if(b < 0){
           if((b - a + 1) % 2 == 0){
               cout << "Positive" << endl;
           }else{
               cout << "Negative" << endl;
           }
       }else{
           cout << "Zero" << endl;
       }
   }
    return 0;
}
