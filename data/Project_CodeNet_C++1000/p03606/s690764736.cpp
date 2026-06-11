#include <bits/stdc++.h>
using namespace std;

int	main(void)
{
  int times, start, end, people = 0;
  cin >> times;
  
  while (times > 0)
  {
    cin >> start >> end;
    people += (end - start) + 1;
    times--;
  }
  
  cout << people << endl;
    
}