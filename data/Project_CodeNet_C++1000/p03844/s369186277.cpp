#include <iostream>
#include <string>
using namespace std;

int main(){
    int a,b;
    string op;
    cin >> a >> op >> b;
    if(op=="+"){
        cout << (a+b) << endl;
    } else {
        cout << (a-b) << endl;
    }
}

int min(int a,int b){
    if(a-b>0) return b;
    return a;
}

int max(int a,int b){
    if(a-b>0) return a;
    return b;
}

int gcd(int a,int b){
    if(a<b) return gcd(b,a);
    if(b==0) return a;
    return gcd(b,a%b);
}