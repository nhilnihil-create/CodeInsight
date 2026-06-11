#include <iostream>
using namespace std;
void ABC50(void);
void ABC52(void);
void ABC53(void);
void ABC54(void);
void ABC55(void);
void ABC56(void);
void ABC57(void);
void ABC58(void);
void ABC59(void);

int main(void){
    ABC52();
    return 0;
}

void ABC52(void){
    int a,b,c,d;
    cin >> a>>b>>c>>d;
    if(a*b>c*d)cout<<a*b<<endl;
    else cout<<c*d<<endl;
}
