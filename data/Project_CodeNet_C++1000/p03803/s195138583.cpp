#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vll;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int A, B;

  cin >> A >> B;

  if (A == 1)
    {
    A = 14;
    }
  if (B == 1)
    {
    B = 14;
    }

  if (A > B)
    {
    cout << "Alice" << endl;
    }
  else if (A < B)
    {
    cout << "Bob" << endl;
    }
  else
     {
    cout << "Draw" << endl;
    }
}
