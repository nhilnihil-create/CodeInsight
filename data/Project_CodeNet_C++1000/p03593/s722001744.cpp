#include <bits/stdc++.h>
using namespace std;

int main(){
  constexpr int Nalp= 26;
  int H,W;
  cin >> H >> W;

  const int Cap_odd= (H%2==1 && W%2==1) ? 1
                                        : 0;
  const int Cap_2mod4= (H%2==1 && W%2==1) ? (H-1)/2+ (W-1)/2
                      :(H%2==1 && W%2==0) ? W/2
                      :(H%2==0 && W%2==1) ? H/2
                                          : 0;
  vector<int> freq(Nalp);
  string buf;
  for(int i=0; i<H; i++){
    cin >> buf;
    for(auto c:buf){
      freq.at(c-'a')++;
    }
  }

  int cnt_odd= 0;
  int cnt_2mod4= 0;
  for(auto f:freq){
    if(f%2==1){ cnt_odd++; }
    else if(f%4==2){ cnt_2mod4++; }
  }

  string ans= (cnt_odd <= Cap_odd && cnt_2mod4 <= Cap_2mod4) ? "Yes"
                                                             : "No";

  cout << ans << endl;
}