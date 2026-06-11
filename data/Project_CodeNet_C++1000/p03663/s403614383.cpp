#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

const string HIDDEN = "";

int query_count = 0;

string query(const string& q) {
  query_count++;
  if (query_count > 64) {
    cerr << "Too many queries!" << endl;
    exit(1);
  }

  cout << "? " << q << endl;
  if (HIDDEN.empty()) {
    string response;
    cin >> response;
    return response;
  } else {
    int64 qi = stoll(q);
    int64 hi = stoll(HIDDEN);
    if ((qi <= hi && q <= HIDDEN) || (qi > hi && q > HIDDEN)) {
      return "Y";
    } else {
      return "N";
    }
  }
}

void output(const string& q) {
  cout << "! " << q << endl;
}

int main() {
  string r1 = query("1000000000000");
  if (r1 == "Y") {
    // The answer is 10^k
    string q = "9";
    while (true) {
      if (query(q) == "Y") {
        string ans = "1";
        while (ans.size() < q.size()) ans += "0";
        output(ans);
        return 0;
      } else {
        q += "9";
      }
    }
  }

  int size = -1;
  for (int d = 9; d >= 1; d--) {
    string q = "1";
    while (q.size() < d) q += "0";
    if (query(q) == "Y") {
      size = d;
      break;
    }
  }

  if (size < 0) {
    cerr << "Unexpected!" << endl;
    exit(1);
  }

  if (DEBUG) {
    cout << "size: " << size << endl;
  }

  string ans = "";
  for (int d = 0; d < size; d++) {
    int l = 0;
    int r = 9;
    if (d == 0) {
      l = 1;
    }

    while (l < r) {
      if (d < size - 1) {
        int m = (l + r + 1) / 2;
        string q = ans + to_string(m);
        string response = query(q);
        if (response == "Y") {
          l = m;
        } else {
          r = m - 1;
        }
      } else {
        int m = (l + r) / 2;
        string q = ans + to_string(m) + "0";
        string response = query(q);
        if (response == "Y") {
          r = m;
        } else {
          l = m + 1;
        }
      }
    }
    ans += to_string(l);
  }

  output(ans);
}