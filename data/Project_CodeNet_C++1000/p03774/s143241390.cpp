#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  int n, m;
  cin >> n >> m;
  int check_x[m], check_y[m], stud_x[n], stud_y[n];
  for(int i = 0; i < n; i++)
    cin >> stud_x[i] >> stud_y[i];
  for(int i = 0; i < m; i++)
    cin >> check_x[i] >> check_y[i];
  for(int i = 0; i < n; i++)
  {
    int min_index = 1;
    int min = abs( check_x[0] - stud_x[i] ) + abs( check_y[0] - stud_y[i] );
    for(int j = 1; j < m; j++)
      if( abs( check_x[j] - stud_x[i] ) + abs( check_y[j] - stud_y[i] ) < min )
      {
        min = abs( check_x[j] - stud_x[i] ) + abs( check_y[j] - stud_y[i] );
        min_index = j + 1;
      }
    cout << min_index << "\n";
  }
}