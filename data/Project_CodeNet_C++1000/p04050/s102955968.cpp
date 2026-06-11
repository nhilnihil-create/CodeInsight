#include <bits/stdc++.h>
#define long long long
#define ull unsigned long long
#define up(i,a,b) for (int i=a; i<=b; i++)
#define upadj(i,adj) if (adj.size()>0) up(i,0,adj.size()-1)
#define down(i,a,b) for (int i=a; i>=b; i--)
#define endl '\n'
#define pb push_back
#define X first
#define Y second
#define II pair<int, int>
#define III pair<int, pair<int, int> >
#define V vector
#define debug(X) cerr<< #X << "=" <<X << endl
#define debug2(X,Y)  cerr<< #X << "=" <<X << ", " << #Y << "=" <<Y << endl
#define show(X,a,b) {cerr << #X << " = "; up(__,a,b) cerr << X[__] << ' '; cerr << endl;}
#define gc getchar
#define pc putchar
using namespace std;

inline void read(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for (;((c<48 || c>57) && c != '-') ;c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
inline void writeln(int x){

         char buffor[21];
         register int i=0;
         int neg=0; if (x<0) {neg=1; x= -x;}
         do{
               buffor[i++]=(x%10)+'0';
               x/=10;
            } while(x);
           i--;
           if (neg) pc('-');
           while(i>=0) pc(buffor[i--]);
           pc('\n');
       }
int n,m;
int a[102];
void input()
{
    cin>>n>>m;
    up(i,1,m) cin>>a[i];
}

void solve()
{
    if (m==1)
    {
        cout<<a[1]<<endl;
        if (a[1]==1) cout<<1<<endl; else cout<<2<<endl;
        if (a[1]==1) cout<<1<<endl;
        else cout<<a[1]-1<<" "<<1<<endl;
        return;
    }
    int cntodd= 0;
    up(i,1,m)
     if (a[i]%2==1) cntodd++;
    if (cntodd>=3)
    {
        cout<<"Impossible"; return;
    }
    int odd1= -1,odd2= -1;
    up(i,1,m)
     if (a[i]%2==1)
     {
         if (odd1==-1)
         {
             odd1= a[i]; swap(a[i],a[1]);
         }
         else if (odd2== -1)
         {
             odd2= a[i]; swap(a[i],a[m]);
         }
     }
     up(i,1,m) cout<<a[i]<<" ";
     cout<<endl;
     if (a[1]==1) cout<<m-1<<endl;
     else cout<<m<<endl;
     if (a[1]>1) cout<<a[1]-1<<" ";
     up(i,2,m-1) cout<<a[i]<<" ";
     cout<<a[m]+1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef I_Love_Pork
    #define TASK "tmp"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    #endif

    input();
    solve();

    return 0;
}
