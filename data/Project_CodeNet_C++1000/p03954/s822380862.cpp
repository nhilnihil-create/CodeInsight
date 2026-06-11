#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;

namespace ancient {
  bool seq [MAX_N];
 
  int smooth_subseq (int a, int b) {
    bool cmade = false;
    // cout << a << " " << b << ";\n";
    if (a == b) return 0;
    if (seq[a] == seq[b]) {
      for (int i = a; i <= b; i++) {
        if (seq[i] != seq[a]) {
          seq[i] = seq[a];
          cmade = true;
        }
      }
    } else {
      for (int i = a; i <= ((a+b-1)/2); i++) {
        if (seq[i] != seq[a]) {
          seq[i] = seq[a];
          cmade = true;
        }
      }
      for (int i = ((a+b+1)/2); i <= b; i++) {
        if (seq[i] != seq[b]) {
          seq[i] = seq[b];
        }
      }
    }
    return (cmade ? (b-a)/2 : 0);
  }
 
  int check (vector<int> bits) {
    int length, maxt = 0, cstart = 0, cend, ct;
    bool inseq = true;
 
    length = bits.size();
    seq[0] = bits[0];
    for (int i = 1; i < length-1; i++) {
      seq[i] = bits[i];
      if (seq[i] == seq[i-1]) {
        if (inseq) {
          cend = i-1;
          ct = smooth_subseq(cstart, cend);
          if (maxt < ct) maxt = ct;
          inseq = false;
        }
      } else {
        if (!inseq) {
          cstart = i-1;
          inseq = true;
        }
      }
    }
    seq[length-1] = bits[length - 1];
    if (inseq) {
      cend = length-1;
      ct = smooth_subseq(cstart, cend);
      if (maxt < ct) maxt = ct;
      inseq = false;
    }

    return seq[length / 2];
  }
}

int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  n = 2 * n - 1;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int ans = 0;
  for (int k = 1 << 20; k != 0; k /= 2) {
    vector<int> test;
    for (int i = 0; i < n; i++) {
      test.push_back(arr[i] >= ans + k);
    }

    if (ancient::check(test)) {
      ans += k;
    }
  }

  cout << ans << endl;
}
