#include <iostream>


using namespace std;

int main(){
 int a,b,c,d;
 int A,B,ans;

 cin >> a >> b >> c >> d;
 A = a*b;
 B = c*d;

 if (A >= B){
     cout << A << endl;
 }else{
     cout << B << endl;
 }

    return 0;
}