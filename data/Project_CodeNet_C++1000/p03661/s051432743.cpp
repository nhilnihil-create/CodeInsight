#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<algorithm>
#include<utility>
#include<math.h>

using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

const int INF = 1<<30;

int main(){
  int n;cin>>n;
  vector<int> a(n);
  ll sum=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    sum += (ll)a[i];
  }
  ll snuke=0;
  ll ans=ll(1e15);
  for(int i=0;i<n-1;i++){
    snuke += (ll)a[i];
    ans = min(ans, abs(sum-2*snuke));
  }
  cout<<ans<<endl;
}
