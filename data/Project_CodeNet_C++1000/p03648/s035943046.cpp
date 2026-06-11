#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int main() {
  long long a;
  cin >> a;
  long long t=a%50;
  long long u=a/50;
  vector<long long> b(50);
for (int i=0;i<50;i++){
    b.at(i)=49+u-t;
}
for (int i=0;i<t;i++){
    b.at(i)+=51;
}
cout << 50 << endl;
rep(i,49){
    cout << b.at(i) << " ";
}
cout << b.at(49) << endl;
}