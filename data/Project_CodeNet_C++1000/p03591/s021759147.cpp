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
string s;
cin >> s;
if(s.size()<4){
    cout << "No"<<endl;
}
else{
if(s.at(0)=='Y'&&s.at(1)=='A'&&s.at(2)=='K'&&s.at(3)=='I')cout <<"Yes"<<endl;
else cout <<"No"<<endl;
}
 }
