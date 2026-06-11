#include<bits/stdc++.h>
using namespace std;
int main(){
   int a,b,c;
   cin >> a >> b >> c;
   int an,bn,cn;
   int cnt=0;
   bool flg=true;
   while(flg){
       if(a%2==0 && b%2==0 && c%2==0){
           if(a==b && b==c && c==a){
               cnt=-1;
               flg = false;
           }else{
               an = (b+c)/2;
               bn = (c+a)/2;
               cn = (a+b)/2;
               cnt++;
               a=an;
               b=bn;
               c=cn;
               //cout << "a " << a << " b " << b << " c " << c << endl;
           }
       }else{
           flg = false;
       }
   }
   cout << cnt << endl;
}


