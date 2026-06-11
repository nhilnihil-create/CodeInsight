
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
  int64_t n;    // input

  int64_t i, j;    // subscript
  int     eao;     // even and odd

  int64_t  sum;
  bool     default_flag;
  bool     plus_flag, minus_flag;
  int64_t  ope_count;
  int64_t  plus_count,  minus_count;


  /* Input, Array_Proclamation */
  cin >> n;
  vector<int64_t> a(n);

  for(i=0; i<n; i++)
  {
    cin >> a.at(i);
  }


  /* Initialize */
  sum       = 0;
  ope_count = 0;
  eao       = 0;

  default_flag = true;
  plus_flag    = false;
  minus_flag   = false;


  /* Calculation */
  while(eao < 2)
  {
    for(i=0; i<n; i++)
    {

      sum += a.at(i);

      if(default_flag == true)
      {

        default_flag = false;
        if(eao == 0)
        {
          while(sum <= 0)
          {
            ope_count++;
            sum++;
          }
          plus_flag = true;
        }
        else if(eao == 1)
        {
          while(sum >= 0)
          {
            ope_count++;
            sum--;
          }
          minus_flag = true;
        }

      }

      else if(plus_flag == true)
      {

        while(sum >= 0)
        {
          ope_count++;
          sum--;
        }

        plus_flag  = false;
        minus_flag = true;

      }

      else if(minus_flag == true)
      {

        while(sum <= 0)
        {
          ope_count++;
          sum++;
        }

        plus_flag  = true;
        minus_flag = false;

      }

    }

    if(eao == 0)
    {
      plus_count  = ope_count;
    }
    else if(eao == 1)
    {
      minus_count = ope_count;
    }
    default_flag = true;
    plus_flag    = false;
    minus_flag   = false;

    sum = 0;
    ope_count = 0;

    eao++;
  }
  
  ope_count = min(plus_count, minus_count);

  /* Output */
  cout << ope_count << endl;


  return 0;

}


/* entity */
//  - none -


