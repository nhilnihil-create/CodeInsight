#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int w,h,n;
  cin >> w >> h >> n;

  vector<vector<int>> black(4,vector<int>(0));
  rep(i,n){
    int x,y,a;
    cin >> x >> y >> a;

    a--;
    if(a==0||a==1) black.at(a).push_back(x);
    else black.at(a).push_back(y);
  }

  black.at(0).push_back(0);
  black.at(1).push_back(w);
  black.at(2).push_back(0);
  black.at(3).push_back(h);

  sort(black.at(0).rbegin(), black.at(0).rend());
  sort(black.at(1).begin(), black.at(1).end());
  sort(black.at(2).rbegin(), black.at(2).rend());
  sort(black.at(3).begin(), black.at(3).end());

  int max_x=black.at(0).at(0);
  int min_x=black.at(1).at(0);
  int max_y=black.at(2).at(0);
  int min_y=black.at(3).at(0);

  int whitex=max(0,min_x-max_x);
  int whitey=max(0,min_y-max_y);
  
  //cout << max_x << " " << min_x << " " << max_y << " " << min_y << endl;

  cout << whitex*whitey;
}