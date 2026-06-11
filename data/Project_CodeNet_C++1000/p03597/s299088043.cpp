
/* Preprocess */
#include <bits/stdc++.h>

#define pow(n) (n)*(n)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()


/* Field */
using namespace std;


/* Function */

int main (void) 
{

  /* Variable_Proclamation */
  int N;      // input
  int white;  // input
  int black;  // output

  int field;


  /* Input, Initialize */
  cin >> N;
  cin >> white; // input A


  /* Calculation */
  field = N * N;
  black = field - white;


  /* Output */
  cout << black << endl;


  return 0;

}


