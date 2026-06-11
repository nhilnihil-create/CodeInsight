#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

int main() {
  int H, W; cin >> H >> W;
  int i = 0; int j = 0;
  string s;
  while (i < H){
    while(j < W){
      cin >> s;
      if (s == "snuke"){
   
        printf("%c%d", 'A' + j, i+1);
        return 0;
      }
      j++;
      }
    j = 0;
    i++;
    }
}

