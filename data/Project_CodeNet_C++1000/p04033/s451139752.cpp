#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;



int main() {
int A, B;
cin >> A >> B;
if (A>0 && B>0) cout << "Positive" << endl;
else if((A >= 0 && B <= 0) || (B >= 0 && A <= 0)) cout << "Zero" << endl;
else{
int sa = 0-(A-B+1);
if(sa % 2 == 0) cout << "Positive" << endl;
else cout << "Negative" << endl;




}



}