#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int h,w;
  cin >> h >> w;
  int n;
  cin >> n;
  vector<int> v;
  for(int i = 0;i < n;i++)
  {
    int a;
    cin >> a;
    for(int j = 0;j < a;j++)
    {
      v.push_back(i + 1);
    }
  }
  for(int i = 0;i < h;i++)
  {
    if(i % 2 == 0)
    {
      for(int j = 0;j < w;j++)
      {
        cout << v.at(i * w + j) << " ";
      }
    }
    else
    {
      for(int j = w - 1;j >= 0;j--)
      {
        cout << v.at(i * w + j) << " ";
      }
    }
    cout << "\n";
  }

  return 0;
}
