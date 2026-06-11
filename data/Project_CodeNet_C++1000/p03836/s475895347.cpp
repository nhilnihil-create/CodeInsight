#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main() {
    int sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    string ans="";
    int x=sx,y=sy;
    while(y<ty){ans+="U";y++;}
    while(x<tx){ans+="R";x++;}
    while(y>sy){ans+="D";y--;}
    while(x>=sx){ans+="L";x--;}
    while(y<=ty){ans+="U";y++;}
    while(x<tx){ans+="R";x++;}
    ans+="D";y--;
    ans+="R";x++;
    while(y>=sy){ans+="D";y--;}
    while(x>sx){ans+="L";x--;}
    ans+="U";
    cout<<ans;
}