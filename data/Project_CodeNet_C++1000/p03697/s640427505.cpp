#include<iostream>

using namespace std;

int main(){
    int a, b, s;

    cin >> a >> b;
    s = a + b;
    if(s < 10){
        cout << s << endl;
    }else{
        cout << "error" << endl;
    }
}