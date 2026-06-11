#include "bits/stdc++.h"

using namespace std;

const int INF = 1e9 + 7;

map<long long, string> query;

long long setnum;

string q(string query)
{
  long long num = stoll(query);
  return (num <= setnum == query <= to_string(setnum)) ? "Y" : "N";
}

bool solve()
{
  query.clear();
  long long size, start = 0, last = 10, putN = false;
  while (start < last) {
    long long middle = (start + last) / 2;

    string ans;
    if (query.count(middle)) {
      ans = query[middle];
    } else {
      cout << "? 1" + string(middle, '0') + "\n";
      cout.flush();
      cin >> ans;
      //ans = q('1' + string(middle, '0'));
      query[middle] = ans;
    }
    if (ans == "Y") {
      start = middle + 1;
    } else {
      putN = true;
      last = middle;
    }
  }
  query.clear();
  if(!putN) {
    start = 0, last = 10;
    while (start < last) {
      long long middle = (start + last) / 2;

      string ans;
      if (query.count(middle)) {
        ans = query[middle];
      } else {
        cout << "? 2" + string(middle, '0') + "\n";
        cout.flush();
        cin >> ans;
        //ans = q('2' + string(middle, '0'));
        query[middle] = ans;
      }
      if (ans == "Y") {
        last = middle;
      } else {
        start = middle + 1;
      }
    }
    cout << "! 1" << string(start, '0') << "\n";
    return pow(10LL, start) == setnum;
  }
  query.clear();
  size = start;
  start = pow(10LL, size - 1);
  last = pow(10LL, size) - 1;
  while (start < last) {
    long long middle = (start + last) / 2;

    string res;
    if(query.count(middle)) {
      res = query[middle];
    } else {
      cout << "? " << middle << "0\n";
      cout.flush();
      cin >> res;
      //res = q(to_string(middle * 10));
      query[middle] = res;
    }
    if (res == "Y") {
      last = middle;
    } else {
      start = middle + 1;
    }
  }
  cout << "! " << start << "\n";
  return start == setnum;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  /*for (int i = 1; i <= 1e9; i++) {
    setnum = i;
    if(!solve()) {
      cout << i << "\n";
    }
  }*/
  solve();
}