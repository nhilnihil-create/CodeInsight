#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
   int a,b;
   cin >> a >> b;
   if(a>0){
       cout << "Positive";
       return 0;
   }
   if(a==0||b==0||(a<0&&b>0)){
       cout << "Zero";
       return 0;
   }
   if((b-a)%2){
      cout << "Positive"; 
   }else{
       cout << "Negative";
   }
}