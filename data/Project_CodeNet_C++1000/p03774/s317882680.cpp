#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
  int n, m;
  cin >> n >> m;
  
  int sd[n][2], cp[m][2];
  
  for (int i = 0; i < n; i++)
    cin >> sd[i][0] >> sd[i][1];
  
  for (int j = 0; j < m; j++)
    cin >> cp[j][0] >> cp[j][1];
  
  
  for (int i = 0; i < n; i++) {
    
    int temp[2] = {0, 0};
    
    for (int j = 0; j < m; j++) {
      int dist = 
        abs(cp[j][0] - sd[i][0]) + abs(cp[j][1] - sd[i][1]);
      
      if (j == 0) {
        temp[0] = dist;
        temp[1] = 1;
      }
      else {
        if (temp[0] > dist) {
          temp[0] = dist;
          temp[1] = j + 1;
        }
      }
    }
    
    cout << temp[1] << endl;
  }
}