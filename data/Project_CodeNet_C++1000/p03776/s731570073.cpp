#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
long long comb[51][51];
long long combination(int n, int r){
  if(!r)comb[n][r] = 1;
  if(r==1)comb[n][r] = n;
  if(n==r)comb[n][r] = 1;
  if(comb[n][r]){return comb[n][r];}
  comb[n][r]=combination(n-1,r-1)+combination(n-1,r);
  return comb[n][r];
}
int main(){
  int n,A,B;cin>>n>>A>>B;
  vector<long long> a(n);
  for(int i = 0; n > i; i++)cin>>a[i];
  sort(a.begin(),a.end(),greater<long long>());
  double ans = 0.0;
  for(int i = 0; A > i; i++)ans += (double)a[i]/A;
  cout << fixed << setprecision(10) << ans << endl;
  int i = A-1;
  for(; 0 <= i && a[i]==a[A]; i--);i++;
  int j = A;
  for(; n > j && a[j]==a[A]; j++);j--;
  if(A==n){
    cout << 1 << endl;
    return 0;
  }
  if(a[0] == a[A]){
    long long kos = 0LL;
    for(int z = A-i; min(B,j-i+1) >= z;z++){
      //z = (0,A-i) ~ ()
      //cout << z << endl;
      
      kos += combination(j-i+1,z);
    }
    cout << kos << endl;
  }else{
    cout << combination(j-i+1,A-i) << endl;
  }

}