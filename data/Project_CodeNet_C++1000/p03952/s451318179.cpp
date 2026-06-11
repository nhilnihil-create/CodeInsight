#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n, x;
  cin >> n >> x;
  if(x == 1 || x == 2 * n - 1){
    cout << "No" << endl;
  }else if(n == 2 && x == 2){
    cout << "Yes" << endl;
    cout << 1 << endl << 2 << endl << 3 << endl;
  }else{
    vector < ll > ans(2 * n - 1, 0);
    set < ll > s;
    for(int i = 1; i <= 2 * n - 1; i++) s.insert(i);
    if(x != 2){
      ans[n - 2] = x - 1;
      ans[n - 1] = x;
      ans[n] = x + 1;
      ans[n + 1] = x - 2;

      s.erase(x - 1);
      s.erase(x);
      s.erase(x + 1);
      s.erase(x - 2);
    }else{
      ans[n - 2] = 3;
      ans[n - 1] = 2;
      ans[n] = 1;
      ans[n + 1] = 4;

      s.erase(1);
      s.erase(2);
      s.erase(3);
      s.erase(4);
    }

    cout << "Yes" << endl;
    for(int i = 0; i < 2 * n - 1; i++){
      if(ans[i] == 0){
        ans[i] = *s.begin();
        s.erase(s.begin());
      }
      cout << ans[i] << endl;
    }
  }
}
