
/* include */
#include <bits/stdc++.h>

#define pow(n) (n)*(n)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

/* function */
//  - none - 


/* code */
int main (void) 
{

  /* Variable_Proclamation */
  int N;    // input
  string ans;  // output

  int i, j, k;    // subscript
  int count;


  /* Input, Array_Proclamation */
  cin >> N;
  vector<int> A(N);


  for(i=0; i<N; i++)
  {
    cin >> A.at(i);
  }


  /* Initialize */
  count = 0;



  /* Calculation */
  for(i=0; i<N; i++)
  {
    if( (A.at(i) %2) != 0 )
    {
      count++;
    }
  }

  

  /* Output */
  if(count %2 == 0)
  {
    ans = "YES";
  }
  else
  {
    ans = "NO";
  }
  

  cout << ans << endl;


  return 0;

}


/* entity */
//  - none -


