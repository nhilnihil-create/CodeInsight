#include <bits/stdc++.h>
using namespace std;
int main(){
    int b = 0;
    string a = "CODEFESTIVAL2016",s;
   cin >> s;
   for(int i=0;i<16;i++){
       if(s[i]!=a[i]) b++;
   }
   cout << b << endl;
}