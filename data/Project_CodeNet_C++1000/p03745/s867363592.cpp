#include <iostream>
#include <vector>
using namespace std;

int findNextSectionIndex(vector<int> &a, int sectionIndex) {
  int diff = 0;
  for (int i = sectionIndex; i < (a.size() - 1); i++) {
    int newDiff = a.at(i + 1) - a.at(i);

    if (diff > 0 && newDiff < 0 || diff < 0 && newDiff > 0) {
      int newSectionIndex = i + 1;
      return newSectionIndex;
    }
    if (newDiff != 0) {
      diff = newDiff;
    }
  }
  return a.size();
}

int main() {
  int N;
  cin >> N;
  vector<int> a = vector<int>(N);
  for (int i = 0; i < a.size(); i++) {
    cin >> a.at(i);
  }

  int index = 0;
  int count = 0;
  while (index < a.size()) {
    index = findNextSectionIndex(a, index);
    count++;
  }
  cout << count << endl;
  return 0;
}