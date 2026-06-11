#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d;
    cin >> a >> b >> c ;
    if(a==b && b==c){
        d=1;
    }else if(a==b || b==c ||a==c){
        d=2;
    }else{
        d=3;
    }
    cout << d << endl;
  


}
