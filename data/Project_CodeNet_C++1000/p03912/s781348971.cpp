#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define MAX_N 100005

int N;
LL M;
LL X[MAX_N];
int MAP[MAX_N], MAP2[MAX_N];
set<int> SET;

void input()
{
  cin >> N >> M;
  for (size_t i = 0; i < N; i++) {
    scanf("%lld", &X[i]);
  }
}

int main()
{
  input();

  for (size_t i = 0; i < N; i++) {
    MAP[X[i]%M]++;
    if(!SET.insert(X[i]).second){
      MAP2[X[i]%M]++;
      SET.erase(X[i]);
    }
  }

  LL ans = 0;
  for (int i = 1; i < (M+1)/2; i++) {
    LL tmp = min(MAP[i], MAP[M-i]);
    LL tmp2;
    LL L = (MAP[i] - MAP2[i]*2);
    if(tmp >= L)
      tmp2 = (MAP2[i]*2 - (tmp - L))/2;
    else
      tmp2 = MAP2[i];
    LL tmp3;
    L = (MAP[M-i] - MAP2[M-i]*2);
    if(tmp >= L)
      tmp3 = (MAP2[M-i]*2 - (tmp - L))/2;
    else
      tmp3 = MAP2[M-i];
    ans += tmp + tmp2 + tmp3;
    //cerr << tmp << " " << tmp2 << " " << tmp3 << endl;
  }
  ans += MAP[0]/2;
  if(M%2 == 0){
    ans += MAP[M/2]/2;
  }
  cout << ans << endl;

  return 0;
}
