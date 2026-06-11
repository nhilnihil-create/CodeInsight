#include <bits/stdc++.h>
using namespace std;

int main() {
int sx,sy,tx,ty;
cin >> sx>>sy>>tx>>ty;
string a,A,b,B;
int dx = tx-sx;
int dy = ty-sy;
for(int i=0;i<dx;i++){
    a+="R";
    b+="L";
}
for(int j=0;j<dy;j++){
    a+="U";
    b+="D";
}
A="DR"+a+"UL";
B="UL"+b+"DR";
cout <<a<<b<<A<<B<<endl;  
}