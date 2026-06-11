#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for(int i=0;i<c;++i)
int main(){
int a;
cin >> a;
int e = (a/100);
int f =((a%100)/10);
int g = (((a%100)%10)/1);
int h = (g*100)+(f*10)+(e*1);
if(a==h){
    cout << "Yes" << endl;
}else{
    cout << "No" << endl;
}
return 0;
}