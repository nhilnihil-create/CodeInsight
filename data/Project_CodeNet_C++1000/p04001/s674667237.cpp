#include <bits/stdc++.h>
using namespace std;

long join_number(vector<int> &num, int start, int end) {
  long sum = 0;
  int digit = end - start;
  for (int i = 0; i < digit; i++) {
    sum += num.at(start + i) * pow(10, digit - i - 1);
  }
  return sum;
}

vector<long> split_number(vector<int> &num, int start, int pcount) {
  if (pcount == 0) {
    return {join_number(num, start, num.size())};
  }

  vector<long> subset;
  for (int i = start; i < num.size() - pcount; i++) {
    long first_num = join_number(num, start, i + 1);
    vector<long> after_list = split_number(num, i + 1, pcount - 1);
    
    for (long number : after_list) {
      subset.push_back(first_num + number);
    }
  }
  return subset;
}

int main() {
  string S;
  cin >> S;

  vector<int> num(S.size());
  for (int i = 0; i < num.size(); i++) {
    num.at(i) = 0 + S.at(i) - 48;
  }

  long sum = 0;
  for (int i = 0; i < num.size(); i++) {
    for (long n : split_number(num, 0, i)) {
      sum += n;
    }
  }
  cout << sum << endl;
}
