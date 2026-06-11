#include <bits/stdc++.h>
using namespace std;

int main (void)
{
  int n, count;
  int i,nagare;
  bool start_flag;
  
  cin >> n;
  vector<long long int> a(n);
  for(i=0; i<n; i++)
  {
    cin >> a[i];
  }

  count = 0;
  nagare = 1;
  start_flag = true;

  for(i=0; i<n-2; i++)
  {
    if(start_flag == true && a[i] == a[i+1])continue;
    if(a[i] < a[i+1])nagare = 1;
    if(a[i] > a[i+1])nagare = 0;
    if(nagare == 1)
    {
      if(a[i+1] > a[i+2])
      {
        count++;
        // test_data(i);
        i++;
        start_flag = true;
      }
      else
      {
        start_flag = false;
      }
    }
    
    if(nagare == 0)
    {
      if(a[i+1] < a[i+2])
      {
        count++;
        // test_data(i);
        i++;
        start_flag = true;
      }
      else
      {
        start_flag = false;
      }
    }

  }  
  count++;
  cout << count << endl;
  return 0;
}
