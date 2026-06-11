#include<bits/stdc++.h>
using namespace std;
long long comb(long long x,long long y){
  long long z = 1;
  for(long long i=0;i<y;i++) z = z*(x-i)/(i+1);
  return z;
}
int main(){
  cout << fixed << setprecision(10);
  long long n,a,b,i,ans = 0,al,c = 0;cin >> n >> a >> b;
  long long v[n];
  for(i=0;i<n;i++) cin >> v[i];
  sort(v,v+n,greater<long long>());
  for(i=0;i<a;i++) ans += v[i];
  cout << double(ans)/a << "\n";
  ans = 0;al = count(v,v+n,v[a-1]);
  for(i=0;i<a;i++) c += (v[i]==v[a-1]);
  ans += comb(al,c);
  if(v[0] != v[a-1]){
    cout << ans << "\n";return 0;
  }
  for(i=a;i<b;i++){
    if(v[i]==v[a-1]){
      c++;ans += comb(al,c);
    } else break;
  }
  cout << ans << "\n";
  return 0;
}