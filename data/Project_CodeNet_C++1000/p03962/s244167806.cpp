#include <iostream>
#include <set>

using namespace std;

int main()	{
  int a, b, c;
  cin >> a >> b >> c;
  set<int> paint;
  paint.insert(a);
  paint.insert(b);
  paint.insert(c);
  int count;
  for (auto it : paint)
    count++;
  cout << count << endl;
  return 0;
}