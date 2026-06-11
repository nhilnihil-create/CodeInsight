#include <iostream>
using namespace std;
int main() {
    //a<= c && b>= c
    int a,b,c = 0;
    bool yn = false;
    cin >> a >> b >> c;
    if(a <= b){
        if(b >= c){
            yn = true;
        }
    }
    if(yn == false){
        cout << "No";
    }else{
        cout << "Yes";
    }
    return 0;
}
