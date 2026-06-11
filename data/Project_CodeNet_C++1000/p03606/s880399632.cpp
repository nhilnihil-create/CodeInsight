#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
 int n;
 cin >> n;
 VI l(n);
 VI r(n);
 ll sum=0;
 rep(i,n){
     cin >> l.at(i) >> r.at(i);
     sum+=r.at(i)-l.at(i)+1;
 }
 cout << sum << endl;
}