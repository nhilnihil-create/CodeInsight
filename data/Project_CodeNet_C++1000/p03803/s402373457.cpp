#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(void){
    int A,B;
    cin >> A >> B;
    if(A == 1)A+=13;
    if(B == 1)B+=13;
    
    string ans;
    if(A>B){
        ans = "Alice";
    }
    if(A<B){
        ans = "Bob";
    }
    if(A == B){
        ans = "Draw";
    }
    cout << ans << endl;
}
