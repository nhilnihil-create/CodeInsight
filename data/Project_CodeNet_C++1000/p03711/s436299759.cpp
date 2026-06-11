//...Hare..Krishna..//
//...Hare..Krishna...//
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double d;

#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (abs(a*b)/gcd(a,b))
#define sqr(a) (a*a)

#define tt int t; cin>>t; while(t--)
#define lo(i, a, b) for(int i=a; i<=b; i++)
#define rlo(i, a) for(int i=a; i>0; i--)
#define be(a) a.begin(),a.end()
#define sz(x) x.size();
#define nl cout<<"\n";
#define sp cout<<" ";
#define Y cout<<"YES"<<endl;
#define N cout<<"NO"<<endl;
#define nlng long long n; cin>>n;
#define nint int n; cin>>n;
#define br break;
#define cn continue;
#define vec vector < int >
#define vecll vector < long long >
#define op() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int main()
{
    op();
    int x,y,l,k;
    map < int ,int > m;
    m[1]=m[3]=m[5]=m[7]=m[8]=m[10]=m[12]=1;
    m[4]=m[6]=m[9]=m[11]=2;
    m[2]=3;
 cin>>x>>y;
 if(m[x]==1 && m[y]==1 || m[x]==2 && m[y]==2  || m[x]==3 && m[y]==3)
    cout<<"Yes";
 else
    cout<<"No";




    return 0;
}

