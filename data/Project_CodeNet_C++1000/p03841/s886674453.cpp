#include <iostream>

using namespace std;

const int MAX_N = 505;

void failure () {
  cout << "No" << endl;
  exit(0);
}

void error () {
  cerr << "==== ERROR ====" << endl;
}

int kth [MAX_N];
int arr [MAX_N * MAX_N];
int cnt [MAX_N];
int spec [MAX_N * MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  
  for (int i = 1; i <= n; i++) {
    cin >> kth[i];
    spec[kth[i]] = i;
  }

  for (int i = 1; i <= n * n; i++) {
    if (spec[i] != 0) {
      if (cnt[spec[i]] != spec[i] - 1) failure();
      arr[i] = spec[i];
      cnt[spec[i]]++;
    } else {
      // find the leftmost spec we aren't ready for
      pair<int, int> cur_spec = make_pair(MAX_N * MAX_N, -1);
      for (int j = 1; j <= n; j++) {
        if (i < kth[j] && cnt[j] < j - 1) {
          cur_spec = min(cur_spec, make_pair(kth[j], j));
        }
      }

      if (cur_spec.second != -1) {
        arr[i] = cur_spec.second;
        cnt[cur_spec.second]++;
      } else {
        // find anything that passed and isn't full
        int cur = -1;
        for (int j = 1; j <= n; j++) {
          if (kth[j] < i && cnt[j] < n) {
            cur = j;
          }
        }

        if (cur != -1) {
          arr[i] = cur;
          cnt[cur]++;
        } else {
          failure();
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cnt[i] = 0;
  }

  for (int i = 1; i <= n * n; i++) {
    cnt[arr[i]]++;
    if (spec[i] != 0) {
      if (cnt[spec[i]] != spec[i]) {
         error();
        //cerr << "not kth of " << spec[i] << endl;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (cnt[i] != n) {
      error();
      //cerr << "not n of " << i << endl; 
    }
  }

  cout << "Yes" << endl;
  for (int i = 1; i <= n * n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
