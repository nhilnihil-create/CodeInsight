
/* Preprocess */
#include <bits/stdc++.h>

#define pow(n) (n)*(n)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()


/* Field */
using namespace std;


/* function */

int main (void) 
{

  /* Variable_Proclamation */
  int A, B;  // 水を入れる量 (*100) (A<B)
  int C, D;  // 砂糖を入れる量 (C<D)
  int E;     // 100gに溶ける砂糖
  int F;     // ビーカーの最大容量

  int i, j, k, l;    // subscript
  int trial; // ループを回す回数
  int capa_i, capa_j, capa_k, capa_l;

  int water;
  int suger;
  int can_melt;
  int beaker;

  int ans_suger, ans_beaker;
  double con, max_con; // concentration（濃度）


  /* Input, Resize, Initialize */
  cin >> A >> B;
  cin >> C >> D;
  cin >> E;
  cin >> F;

  trial   = 31;
  max_con = -1;


  /* Calculation */

  capa_i = F;
  for(i=0; capa_i -(A*100)*i >= 0; i++)
  {
    capa_j = capa_i -(A*100)*i;

    for(j=0; capa_j -(B*100)*j >= 0; j++)
    {
      capa_k = capa_j -(B*100)*j;

      for(k=0; capa_k -C*k >= 0; k++)
      {
        capa_l = capa_k -C*k;  

        for(l=0; capa_l -D*l >= 0; l++)
        {

            water    = (A*i + B*j) *100;
            can_melt = (A*i + B*j) *E;
            suger    =  C*k + D*l;
            beaker   = water + suger;

            if(can_melt >= suger)
            {
              con = (double)suger / (double)beaker;
              if(max_con < con)
              {
                max_con    = con;
                ans_suger  = suger;
                ans_beaker = beaker;
              }
            }

        }
      }
    }
  }

  // space;
  cout << ans_beaker << " " << ans_suger << endl;

  return 0;

}



