#include <bits/stdc++.h>
#define ll long long
#define INF 1000000000000000
#define rep(i,a,n) for (int i =a; i<n; i++)
using namespace std;

int main() {
  ll H,W; cin >> H >> W;
  ll ans,ans1 = INF,ans2 = INF,ans3 = INF,ans4 = INF;
  rep(i,1,H) {
    ll area1 = W * i;
    ll area2 = (H-i)/2 * W;
    ll area3 = (H-i-(H-i)/2) * W;
    ans1 = min(ans1,max(max(abs(area1-area2),abs(area2-area3)),abs(area3-area1)));
  }
  rep(i,1,H) {
    ll area1 = W * i;
    ll area2 = (W/2) * (H-i);
    ll area3 = (W- W/2) * (H-i);
    ans2 = min(ans2,max(max(abs(area1-area2),abs(area2-area3)),abs(area3-area1)));
  }
  rep(i,1,W) {
    ll area1 = H * i;
    ll area2 = (W-i)/2 * H;
    ll area3 = (W-i-(W-i)/2) * H;
    ans3 = min(ans3,max(max(abs(area1-area2),abs(area2-area3)),abs(area3-area1)));
  }
  rep(i,1,W) {
    ll area1 = H * i;
    ll area2 = (H/2) * (W-i);
    ll area3 = (H-H/2) * (W-i);
    ans4 = min(ans4,max(max(abs(area1-area2),abs(area2-area3)),abs(area3-area1)));
  }
    
  ans = min(min(ans1,ans2),min(ans3,ans4));
  cout << ans << endl;
}