#include <bits/stdc++.h>
using namespace std;

int main() {
 int w,a,b; cin >> w >> a >> b;
 int len1 = b - (w + a), len2 = a - (b + w);
 if (len1 > 0) {
  printf("%d\n" , len1);
 } else if (len2 > 0) {
  printf("%d" , len2);
 } else {
  puts("0");
 }
}