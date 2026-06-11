#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main() {
long long int A,B,C,D,E,F,G; 
cin >> A >> B >> C >> D >> E >> F >> G; 
if(A >= 1 && D >= 1 && E >= 1){
int K = A % 2 + D % 2 + E % 2; 
cout << A + B + D + E - min(K, 3-K) << endl; 
}
else{
cout << A + B + D + E - A % 2 - D % 2 - E % 2 << endl; 
}
}