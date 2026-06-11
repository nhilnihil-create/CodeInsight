#include<bits/stdc++.h>
using namespace std;
int main(){
  int q,h,s,d,n;
  cin >> q >>h >>s >> d >>n;
  cout << (int64_t)((int64_t)(n/2)*min(min(min(8*q,4*h),2*s),d)+(int64_t)(n%2)*min(min(4*q,2*h),s)) << endl;
}
