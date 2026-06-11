#include <bits/stdc++.h>
using namespace std;

int main() {
 int n,m,a,b;
 cin >> n >> m;
 vector<int> vec1(0);
 vector<int> vec2(n);
 for(int i = 0 ; i < m*2 ; i++){
   cin >> a;
   vec1.push_back(a);
 }
 for(int i = 0 ; i < m*2 ; i++){
   b = vec1.at(i);
   vec2.at(b-1) = vec2.at(b-1) + 1;
 }
 for(int i = 0 ; i < n ; i++){
   cout << vec2.at(i) << endl;
 }
}
