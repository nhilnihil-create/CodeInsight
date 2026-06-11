#include <bits/stdc++.h>
using namespace std;

int main(void){
   
   int a,b,c;
   cin >> a >> b >> c;
   map<int,int> m{};
   m[a] = 1;
   m[b] = 1;
   m[c] = 1;
   cout << m.size() <<endl;
}