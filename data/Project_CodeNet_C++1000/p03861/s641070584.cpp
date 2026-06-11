#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
   ll a, b, x;
   cin >> a >> b >> x;
   
   cout << (b/x - a/x) + (a % x == 0) << endl;
   return 0;
}