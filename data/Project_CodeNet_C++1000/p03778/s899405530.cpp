#include <bits/stdc++.h>
#include <math.h>
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
    ABC56();
}

void ABC56(){
    int w,a,b;
    cin>>w>>a>>b;
    if(b>=a&&b<=a+w)cout<<0<<endl;
    else cout<<abs(a-b)-w<<endl;
}