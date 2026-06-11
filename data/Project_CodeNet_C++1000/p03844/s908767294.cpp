#include <iostream>
using namespace std;
void ABC50(void);
void ABC51(void);
void ABC52(void);
void ABC53(void);
void ABC54(void);
void ABC55(void);
void ABC56(void);
void ABC57(void);
void ABC58(void);
void ABC59(void);

int main(void){
    ABC50();
    return 0;
}

void ABC50(void){
    int a,b;
    char c;
    cin >> a >> c >> b;
    if(c=='+'){cout << a+b <<endl;}
    else{cout << a-b << endl;}
}