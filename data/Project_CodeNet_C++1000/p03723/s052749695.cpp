#include<bits/stdc++.h>
using namespace std;
int main(){
int a,b,c;
cin >>a>>b>>c;
int output=0;
int flag = 0;
if(a==b&&b==c&&b%2==0){
output = -1;
flag =1;
}
if(a==b&&b==c&&b%2!=0){
output = 0;
flag =1;
}
while(a%2==0&&b%2==0&&c%2==0&&flag==0){
int aa,bb,cc;
aa = a/2;
bb = b/2;
cc = c/2;
a=bb+cc;
b=aa+cc;
c=aa+bb;
output++;
}

cout << output <<endl; 
}