#include <iostream>
using namespace std;

int main() {
int A,B;
cin >> A >> B;
if(A==B){
    cout <<"Draw"; return 0;
}
if(A==2 || B==1){
    cout << "Bob"; return 0;
}
if(B==2 || A==1){
    cout << "Alice"; return 0;
}
if(A>B){
    cout << "Alice"; return 0;
}
else{
    cout << "Bob"; return 0;
}
return 0;
}