#include <bits/stdc++.h>
using namespace std;

int main() {
 string num;
 cin >> num;
 int n = num.length();
 if(n == 3){
   cout << "ABC" << num << endl;
 }
 else if(n == 2){
   cout << "ABC" << '0' + num << endl;
 }
 else{
   cout << "ABC" << "00" + num << endl;
 }
}
