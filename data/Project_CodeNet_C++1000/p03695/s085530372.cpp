#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  map<int,int> m;

  int N; cin >> N;
  int free = 0;

  for(int i = 0; i < N; i++){
    int tmp;
    cin >> tmp;
    tmp /= 400;
    if(tmp >= 8) {
      free++;
      continue;
    }

    m[tmp]++;
  }
  int color_num = m.size();

  cerr << color_num << " " << free << endl;
  int min_val = max(1, color_num);
  int max_val = color_num + free;

  cout << min_val << " " << max_val << endl;



}
