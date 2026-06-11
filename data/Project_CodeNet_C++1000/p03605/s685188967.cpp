#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for(int i=0;i<c;++i)
int main(){
 int a;
 cin >> a;
 int d = a/10;
 int e = a%10;
 if(d==9||e==9){
     cout << "Yes" << endl;
 }else{
     cout << "No" << endl;
 }
return 0;
}