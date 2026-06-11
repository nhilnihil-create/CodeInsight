#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

long long maxi(long long x, long long y, long long z)	{
  return max(max(x, y), z);
}

long long mini(long long x, long long y, long long z)	{
  return min(min(x, y), z);
}

int main()	{
  long long h, w; // height | width -
  cin >> h >> w;
  if (h % 3 == 0 || w % 3 == 0)	{
	cout << 0 << endl;
    return 0;
  }
  long long S = h * w;
  long long Sa = 0, Sb = 0, Sc = 0; // areas
  long long min = 1000000007;
  for (long long i = 0; i < h; i++)	{
    Sa = (i + 1) * w; // area of largest block
    Sb = (w / 2) * (h - i - 1);
    Sc = S - Sa - Sb;
    long long diff = maxi(Sa, Sb, Sc) - mini(Sa, Sb, Sc);
    if (diff < min)
      min = diff;
    Sb = w * ((h - i - 1) / 2);
    Sc = S - Sa - Sb;
    diff = maxi(Sa, Sb, Sc) - mini(Sa, Sb, Sc);
    if (diff < min)
      min = diff;
  }
  for (long long i = 0; i < w; i++)	{
    Sa = (i + 1) * h;
    Sb = (w - i - 1) * (h / 2);
    Sc = S - Sa - Sb;
    long long diff = maxi(Sa, Sb, Sc) - mini(Sa, Sb, Sc);
    if (diff < min)	{
      min = diff;
    }
    Sb = ((w - i - 1) / 2) * h;
    Sc = S - Sa - Sb;
    diff = maxi(Sa, Sb, Sc) - mini(Sa, Sb, Sc);
    if (diff < min)	{
      min = diff;
    }
  }
  cout << min << endl;
  return 0;
}