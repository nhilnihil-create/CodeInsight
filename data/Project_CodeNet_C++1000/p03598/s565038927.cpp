//include
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath> 
#include <iomanip>
#include <math.h>
#include <utility>
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
int a=0,b=0,c=0,d=0,n,k;

signed main(){
    cin>>n>>k;
    vector<int>x(n);
    rep(i,n)cin>>x[i];
    rep(i,n)
    {
        if(x[i]>k)a=x[i]-k; else a=k-x[i];
        b=min(a,x[i]);
        c+=2*b;
    }
    print(c);
}
