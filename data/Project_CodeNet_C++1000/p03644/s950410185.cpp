//include
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath> 
#include <iomanip>
#include <math.h>
#include <utility>
#include <functional>
//using
using namespace std;
/*using vi = vector <int>;
using vs = vector <string>;
using vc = vector <char>;*/
//vector<vector<char> > hyou(N, vector<char>(N));
//define
#define int long long
#define rep(i,n) for(int i=0; i<n; i++)
#define print(n) cout<<n<<endl;
//グローバル変数宣言
int a=0,b=0,c=0,d=0,n;

signed main(){
   cin>>n;
   if(n<2)print(1)
   else if(n<4)print(2)
   else if(n<8)print(4)
   else if(n<16)print(8)
   else if(n<32)print(16)
   else if(n<64)print(32)
   else if(n<128)print(64)
}
