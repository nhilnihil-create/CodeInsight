#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin>>s>>t;
  int sn = s.length();
  int tn = t.length();
  int sa_acc[sn+1], sb_acc[sn+1], ta_acc[tn+1], tb_acc[tn+1];
  for (int i=0; i<sn+1; i++) {
    sa_acc[i] = 0;
    sb_acc[i] = 0;
  }
  for (int i=0; i<tn+1; i++) {
    ta_acc[i] = 0;
    tb_acc[i] = 0;
  }
  for (int i=0; i<sn; i++) {
    if (s[i] == 'A') {
      sa_acc[i+1] = sa_acc[i] + 1;
      sb_acc[i+1] = sb_acc[i];
    } else {
      sa_acc[i+1] = sa_acc[i];
      sb_acc[i+1] = sb_acc[i] + 1;
    }
  }
  for (int i=0; i<tn; i++) {
    if (t[i] == 'A') {
      ta_acc[i+1] = ta_acc[i] + 1;
      tb_acc[i+1] = tb_acc[i];
    } else {
      ta_acc[i+1] = ta_acc[i];
      tb_acc[i+1] = tb_acc[i] + 1;
    }
  }
  int q;
  cin>>q;
  for (int i=0; i<q; i++) {
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    --a;
    --b;
    --c;
    --d;
    int sa = sa_acc[b+1] - sa_acc[a];
    int sb = sb_acc[b+1] - sb_acc[a];
    int ta = ta_acc[d+1] - ta_acc[c];
    int tb = tb_acc[d+1] - tb_acc[c];
    if ((sa * 2 + sb) % 3 == (ta * 2 + tb) % 3) {
      cout<<"YES"<<endl;
    } else {
      cout<<"NO"<<endl;
    }
  }
}