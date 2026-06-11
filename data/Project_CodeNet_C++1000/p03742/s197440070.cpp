#include<bits/stdc++.h>
using namespace         std;
#define                 int long long
#define                 pb push_back
#define                 mp make_pair
#define st(arr,a)       memset(arr,a,sizeof arr)
#define                 nl cout<<endl
#define                 real signed
#define                 endl '\n'              
#define bitcount(x)     __builtin_popcountll(x)
const int MOD = 1000000007ll;
#define forn(i,a,b)     for(int i=a;i<=b;i++)
#define rfor(i,a,b)     for(int i=a;i>=b;i--)
#define all(x)          x.begin() , x.end()
#define pi pair<int,int>
#define X first
#define Y second
#define N 314159
#define  vi vector<int>
#define  v  vector

signed main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int x,y;
    cin>>x>>y;
    if(x<y)swap(x,y);
    
    if(x-y<=1)cout<<"Brown";
    else cout<<"Alice";




     return 0;

}

//       g++ -g c.cpp ; ./a.exe