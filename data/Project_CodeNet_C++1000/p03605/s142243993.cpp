
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 1999999999
#define MODA 1000000007
#define PI 3.1415926535897932384626433

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
   string str;
   cin >> str;
   int count9 = count(str.begin(), str.end(), '9');
   if(count9 >= 1){
    cout << "Yes" << endl;
   }
   else{
    cout << "No" << endl;
   }
    return 0;
}
