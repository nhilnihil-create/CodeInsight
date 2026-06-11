#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
int A, B;
cin >> A >> B;
 
if(A % 3 == 0) { cout << "Possible" << endl; return 0; }
if(B % 3 == 0) { cout << "Possible" << endl; return 0; }
if((A + B) % 3 == 0) { cout << "Possible" << endl; return 0; }
 
 
cout << "Impossible" << endl;
 return 0;
}