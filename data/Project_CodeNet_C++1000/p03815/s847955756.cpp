#include "bits/stdc++.h"
using namespace std;
int main() {
 long long n;cin>>n;
 cout<<(n%11==0?n/11*2:(n%11<=6?n/11*2+1:n/11*2+2))<<endl;
}
