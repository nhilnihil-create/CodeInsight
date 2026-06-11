#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int A, B, C, D, E, F;
	cin >> A >> B >> C >> D >> E >>F;

  double max_rate = (double)E/(100+E);

  // A,Bで可能な組み合わせ
  set <int> ABset;
  for (int a = 0; a <= 3000; a++) {
    for (int b = 0; b <= 3000; b++) {
      int ABsum = 100*A*a+100*B*b;
      if (ABsum > F) break;
      if (ABsum == 0) continue;
      ABset.insert(ABsum);
    }
  }
  set <int> CDset;
  for (int c = 0; c <= 3000; c++) {
    for (int d = 0; d <= 3000; d++) {
      int CDsum = C*c+D*d;
      if (CDsum > (double)F*max_rate) break;
      if (CDsum == 0) continue;
      CDset.insert(CDsum);
    }
  }
  vector <int> cdset;
  for (std::set<int>::iterator itr = CDset.begin(); itr != CDset.end(); ++itr) {
    cdset.push_back(*itr);
  }


  int ansABCD = A*100;
  int ansCD = 0;
  double ans_rate = 0.;
  for (std::set<int>::iterator itr = ABset.begin(); itr != ABset.end(); ++itr) {
    int maxCD = (*itr)/100*E;
    maxCD = min(F-(*itr), maxCD);
    // 二部探索で探す
    if (cdset.size()==0) break;
    int l = 0;
    int r = cdset.size()-1;
    int m = (l+r+1)/2;
    while (l<r) {
      if (cdset[m] > maxCD) {
        r = m-1;
      } else {
        l = m;
      }
      m = (l+r+1)/2;
    }
    double this_rate = (double)cdset[l]/(cdset[l]+(*itr));
    if (this_rate > ans_rate) {
      ans_rate = this_rate;
      ansCD = cdset[l];
      ansABCD = (*itr) + ansCD;
    }
  }

  cout << ansABCD << " " << ansCD << endl;
  return 0;
}

