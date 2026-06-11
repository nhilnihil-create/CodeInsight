#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
int64_t a, b, x;
 
cin >> a >> b >> x;

int64_t count = 0;

if (a == 0) {
    count = b / x + 1;    
} else {
    count = (b / x) - ((a - 1) / x);
}
 
cout << count << endl;
 
return 0;
}