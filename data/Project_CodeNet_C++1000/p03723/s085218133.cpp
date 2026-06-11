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
int a=0,b=0,c=0,d=0,e=0,f=0,g=0;

signed main(){
    cin>>a>>b>>c;
    if (a%2==1||b%2==1||c%2==1){d=0;}
    else if(a==b&&b==c){d=-1;}
    else{
    rep(i,1000000000)
    {
        e=a/2;f=b/2;g=c/2;d++;a=f+g;b=e+g;c=e+f;
        if(a%2==1||b%2==1||c%2==1)break;
    }}
    print(d);
}
