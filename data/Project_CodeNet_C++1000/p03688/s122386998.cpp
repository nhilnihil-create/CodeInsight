#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

//超数学最高
/*
まずa1<=a2<=...<=anを仮定すると
an-a1>1ならNOを出していい
Var{a1,a2,..an}をa1~anの猫の色の種類数とすると
Var{a1,a2,...an}=xとする。
a1=Var{a2,...an}=if a1 is unique then x-1 else x
an=Var{a1,...a(n-1)}=if an is unique then x-1 else x
a1<=anより
(a1,an)=(x-1,x) or (x-1,x-1) or (x,x)以外ありえない
よって最大値と最小値の差が2以上ならそもそも構築不可能

ここで数列aの値がすべてxの時
x+1<n<2*x  ->No
n=x+1,n>=2*x  ->Yes
である。
n=x+1なら
{a1,...an}={1,2,3,...,x+1}と構築すればいいし
n=2*xなら
{a1,...an}={1,1,2,2,3,3,...x,x}と構築し、nがそれ以上なら
既出の色を追加すればいい。
逆にそれ以外の時は構築できないことは自明。

ここで数列aの値がx-1とxのとき
{a1,...an}={x-1,x-1,...x,x,...x}の時
わからんわクソ
*/

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    sort(ALL(a));
    if(a[n-1]-a[0]>=2){
        cout<<"No"<<endl;
        return 0;
    }
    if(a[n-1]==a[0]){
        int x=a[0];
        if(x+1<n&&n<2*x){
            cout<<"No"<<endl;
        }
        else{
            cout<<"Yes"<<endl;
        }
        return 0;
    }
    else{
        int x=0;
        rep(i,n){
            if(a[0]==a[i]) x++;
        }
        int y=n-x;
        if(x==a[n-1]-1){
            cout<<"Yes"<<endl;
            return 0;
        }
        if(2*(a[n-1]-x)<=y&&x<a[n-1]){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}
