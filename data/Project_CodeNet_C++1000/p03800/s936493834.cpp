#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n;
  cin >> n;
  string s;
  cin >> s;
  string tmp = "SW";
  for(int p = 0; p < 2; p++){
    for(int q = 0; q < 2; q++){
      for(int r = 0; r < 2; r++){
        vector < char > res(n + 1);
        res[n] = tmp[p];
        res[1] = tmp[q];
        res[2] = tmp[r];
        if(res[1] == 'S'){
          if(s[0] == 'o'){
            if(res[n] != res[2]) continue;
          }else if(res[n] == res[2]) continue;
        }else{
          if(s[0] == 'o'){
            if(res[n] == res[2]) continue;
          }else if(res[n] != res[2]) continue;
        }

        char ch = res[n];

        for(int i = 1; i < n - 1; i++){
          if(res[i + 1] == 'S'){
            if(s[i] == 'o') res[i + 2] = res[i];
            else if(res[i] == 'S') res[i + 2] = 'W';
            else res[i + 2] = 'S';
          }else{
            if(s[i] == 'x') res[i + 2] = res[i];
            else if(res[i] == 'S') res[i + 2] = 'W';
            else res[i + 2] = 'S';
          }
        }

        if(res[n] == 'S'){
          if(s[n - 1] == 'o' && res[n - 1] != res[1]) continue;
          else if(s[n - 1] == 'x' && res[n - 1] == res[1]) continue;
        }else{
          if(s[n - 1] == 'o' && res[n - 1] == res[1]) continue;
          else if(s[n - 1] == 'x' && res[n - 1] != res[1]) continue;
        }

        if(res[n] != ch) continue;

        for(int i = 1; i <= n; i++) cout << res[i];
        cout << endl;
        return 0;
      }
    }
  }

  cout << -1 << '\n';
}
