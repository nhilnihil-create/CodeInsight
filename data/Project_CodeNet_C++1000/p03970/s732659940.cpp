#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(int a, int b) {  
  return b != 0 ? gcd(b, a % b) : a;
}//MAX
int lcm(int a, int b) { 
   return a * b / gcd(a, b);
   }
//MIN

 main() {
string s ="CODEFESTIVAL2016";
string t;
cin >> t;
int che =0;
for(int i=0;i<s.size();i++){
    if(s.at(i)!=t.at(i))che++;
}
cout << che << endl;
 }
