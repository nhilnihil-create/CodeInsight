#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool take(vector<int> &bucket, int multi, int k)
{
  size_t i = 0;
  while (i < bucket.size() && k > 0)
  {
    if (bucket[i] >= multi)
    {
      bucket[i] -= multi;
      --k;
    }
    else
    {
      ++i;
    }
  }
  return k == 0;
}

bool f(vector<int> bucket, int H, int W)
{
  int bai4 = (H/2) * (W/2);
  int bai2 = (W/2) * (H%2) + (H/2) * (W%2);

  if (!take(bucket, 4, bai4))
    return false;
  else if (!take(bucket, 2, bai2))
    return false;
  else
    return true;
}

int main()
{
  int H, W;
  cin >> H >> W;
  vector<int> bucket(26, 0);
  for (int h = 0; h < H; ++h)
  {
    string s;
    cin >> s;
    for (int w = 0; w < W; ++w)
    {
      ++bucket[s[w]-'a'];
    }
  }
  
  bool ans = f(bucket, H, W);
  cout << (ans ? "Yes" : "No") << endl;
}