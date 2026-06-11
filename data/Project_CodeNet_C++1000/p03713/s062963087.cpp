#include<bits/stdc++.h>
using namespace std;
long long s1, s2, s3, ans = 10000000000, maxS, minS;

void search(long long A, long long B){
  for ( int a = 1; a < A; a++){
    s1 = a * B;
    int da = A-a;
    s2 = da/2 * B ;
    s3 = da * B - s2;
    maxS = max(s1, max(s2, s3));
    minS = min(s1, min(s2, s3));
    ans = min(ans, maxS-minS );
    s2 = da * (B/2);
    s3 = da * B - s2;
    maxS = max(s1, max(s2, s3));
    minS = min(s1, min(s2, s3));
    ans = min(ans, maxS-minS );
  }
}

int main(){
  int H, W;
  cin >> H >> W;
  search(H, W);
  search(W, H);

  cout << ans << endl;

  return 0;
}