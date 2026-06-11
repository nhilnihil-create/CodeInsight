#include<iostream>
#include <algorithm>
#include <string>
using namespace std;
#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
typedef long long ll;
const int INF = numeric_limits<int>::max();
const int MOD = (1e9 + 7);

 int main(){
   int H, W, ans1, ans2, ans3, ans4, ans5, ans6, ans7, ans8, ans, a, b, c, d;
   cin >> H >> W;
   if(H%3 == 0 || W%3 == 0)
     ans = 0;
   else {a = W/3; b = (W+3)/3; c = H/3; d = (H+3)/3;
   ans1 = max({H*a, (W-a)*(H/2), (W-a)*(H - (H/2))}) - 
              min({H*a, (W-a)*(H/2), (W-a)*(H - (H/2))});
   ans2 = max({H*b, (W-b)*(H/2), (W-b)*(H - (H/2))}) - 
              min({H*b, (W-b)*(H/2), (W-b)*(H - (H/2))});
   ans3 = max({W*c, (H-c)*(W/2), (H-c)*(W - (W/2))}) - 
              min({W*c, (H-c)*(W/2), (H-c)*(W - (W/2))});
   ans4 = max({W*d, (H-d)*(W/2), (H-d)*(W - (W/2))}) - 
              min({W*d, (H-d)*(W/2), (H-d)*(W - (W/2))});
   ans5 = abs(H*a - H*(W-2*a));
   ans6 = abs(H*b - H*(W-2*b)); 
   ans7 = abs(W*c - W*(H-2*c));
   ans8 = abs(W*d - W*(H-2*d));
   ans = min({ans1, ans2, ans3, ans4, ans5, ans6, ans7, ans8});}
   cout << ans << endl;
 }
     
   