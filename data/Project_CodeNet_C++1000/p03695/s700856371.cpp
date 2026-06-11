#include <iostream>
using namespace std;

int main()
{
  int N;
  int a[110];
  cin >> N;
  for(int i = 0; i < N; ++i)
  {
    cin >> a[i];
  }
  
  int colors[8] = {0};
  int over3200 = 0;
  for(int i = 0; i < N; ++i)
  {
    if(a[i] < 3200)
    {
      colors[a[i]/400]++;
    }
    else
    {
      over3200++;
    }
  }
  
  int num = 0;
  for(int i = 0; i < 8; ++i)
  {
    if(colors[i] != 0)
    {
      num++;
    }
  }
  
  int min = num == 0 ? 1 : num;
  int max = num + over3200;
  
  cout << min << " " << max << endl;
}