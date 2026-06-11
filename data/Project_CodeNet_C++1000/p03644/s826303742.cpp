#include<bits/stdc++.h>
using namespace std;
int main(){
 int n;
 cin >> n;
 int x = 1; 
 while(x <= n)
   x <<= 1;
 
 x/=2;
 cout << x;
 return 0;
}
