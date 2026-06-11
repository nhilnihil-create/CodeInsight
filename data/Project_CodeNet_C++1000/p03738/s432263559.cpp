#include <bits/stdc++.h>
#define Tayeb ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
typedef long long ll;
using namespace std;
int main()
{
    Tayeb;
    string A,B;
    cin >> A >> B;

      if(A.length()>B.length())
      cout << "GREATER" << "\n";
      else if(A.length()<B.length())
      cout << "LESS" << "\n";
      else if(A==B)
      cout << "EQUAL" << "\n";
      else
      {
          for(int i=0,j=0; i<A.length()&&j<B.length(); i++,j++)
          {
              if(A[i]!=B[i])
              {
                  if(A[i]>B[i])
                  {
                  cout << "GREATER" << "\n";
                  break;
                  }
                  else if(A[i]<B[i])
                  {
                  cout << "LESS" << "\n";
                  break;
                  }
              }
          }
      }
    return 0;

}
