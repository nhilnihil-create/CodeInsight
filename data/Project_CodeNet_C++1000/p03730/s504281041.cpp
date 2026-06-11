#include <bits/stdc++.h>
using namespace std;


int main(){
int a,b,c;
  cin >> a >> b >> c;
bool flag = false;
for(int i=1;i<=b;i++){
if((i*a)%b==c){
flag=true;
break;  
}
}
if(flag==true) cout << "YES" << endl;
  else cout << "NO" << endl;
  
}