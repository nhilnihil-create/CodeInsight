#include <bits/stdc++.h>

using namespace std;

#define llong long long
#define ii pair<int, int>
#define xx first
#define yy second
#define len(s) ((int)s.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; ++i <= n; )

bool ask(llong num) {
  cout << "? " << num << endl;
  char x; cin >> x;
  return x == 'Y';
}

void answer(llong num) {
  cout << "! " << num << endl;
  exit(0);
}

int digcnt(llong num) { return num == 0 ? 0 : digcnt(num / 10) + 1; } 

llong makenum(llong head, llong l, int fill = 9) {
  for (l -= digcnt(head); l > 0; --l) head = head * 10 + fill;
  return head;
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int ll = 12;
  llong num = 0;
  for (int i = 0; i < ll; ++i) {
    int l = i == 0, r = 9;
    while (l < r) {
      int mid = (r + l) / 2;
      if (ask(makenum(num * 10 + mid, ll))) r = mid;
      else l = mid + 1;
    }
    num = num * 10 + l;
  }
  
  num = makenum(num, ll, 0);
  if (num == (llong)1e11) {
    llong t = 2;
    while (!ask(t)) t *= 10;
    answer(t / 2);
  }
  while (!ask(num - 1)) num /= 10;
  answer(num);

  return 0;
}
