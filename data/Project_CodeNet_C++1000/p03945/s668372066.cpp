#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
  string s;
  cin >> s;

  int from_left[s.size()];
  for (int i = 0; i < s.size(); ++i) {
    if (i == 0)
      from_left[0] = 1;
    else if (s[i] == s[i - 1]) {
      from_left[i] = from_left[i - 1];
    } else {
      from_left[i] = from_left[i - 1] + 1;
    }
  }

  int from_right[s.size()];
  for (int i = s.size() - 1; i >= 0; --i) {
    if (i == s.size() - 1)
      from_right[s.size() - 1] = 1;
    else if (s[i] == s[i + 1]) {
      from_right[i] = from_right[i + 1];
    } else {
      from_right[i] = from_right[i + 1] + 1;
    }
  }

  long long ret = 10000000;
  for (int i = 0; i < s.size(); ++i) {
    ret = min(ret, (long long)(from_left[i] + from_right[i]));
  }

  cout << ret - 2 << endl;

  //int from_left = 0;
  //int left_end = 0;
  //for (int i = 0; i < s.size(); ++i) {
  //  if (i == 0)
  //    from_left = 1;
  //  else if (s[i] == s[i - 1])
  //    ++from_left;
  //  else if (s[i] != s[i - 1] || i == s.size() - 1) {
  //    left_end = i - 1;
  //    break;
  //  }
  //}
  //int from_right = 0;
  //int right_end = 0;
  //for (int i = s.size() - 1; i >= 0; --i) {
  //  if (i == s.size() - 1)
  //    from_right = 1;
  //  else if (s[i] == s[i + 1])
  //    ++from_right;
  //  else if (s[i] != s[i + 1] || i == 0) {
  //    right_end = i;
  //    break;
  //  }
  //}

  //int ret = 0;
  //while (true) {
  //  if (left_end >= right_end)
  //    break;

  //  cout << left_end << " " << right_end << endl;

  //  if (from_left > from_right) {
  //    int prev_left_end = left_end;
  //    for (int i = left_end + 1; i < s.size(); ++i) {
  //      if (s[i] != s[i - 1] || i == s.size() - 1){
  //        left_end = i - 1;
  //        break;
  //      }
  //    }
  //    from_left += left_end - prev_left_end;
  //    ++ret;
  //  } else {
  //    int prev_right_end = right_end;
  //    for (int i = right_end - 1; i >= 0; --i) {
  //      if (s[i] != s[i + 1] || i == 0) {
  //        right_end = i + 1;
  //        break;
  //      }
  //    }
  //    from_right += prev_right_end - right_end;
  //    ++ret;
  //  }
  //}

  return 0;
}