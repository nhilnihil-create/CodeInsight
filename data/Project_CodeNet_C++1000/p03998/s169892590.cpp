#include<bits/stdc++.h>
#define lln long long int
#define llu unsigned lln
#define sc(n) scanf("%d",&n);
#define scl(n) scanf("%lld",&n);
#define scd(n) scanf("%lf",&n);
#define pf(res) printf("%d\n",res);
#define pfl(res) printf("%lld\n",res);
#define pfd(res) printf("%lf\n",res);
#define maxii 100005
using namespace std;
typedef pair<int,int> pii;
typedef pair<lln,lln> pll;
 vector<int> vi[maxii];
 vector<int>:: iterator child;
typedef vector<lln> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;


int arr[maxii];
int arr2[maxii];
bool check[maxii];

bool dfs(int node,int c)
{
    check[node]=true;
    arr2[node]=c;
    for(int child=0;child<vi[node].size();child++)
    {
        if(check[vi[node][child]]==false)
        {
            if(dfs(vi[node][child],c^1)==false)
            {
                return false;
            }
        }
        else if(arr2[node]==arr2[vi[node][child]])
        {
            return false;
        }
        //else if()
    }
    return true;
}

int main()
{
   //string a,b,c;
   stack<char>aa,bb,cc;
   string a,b,c;
   cin>>a>>b>>c;
   int len1=a.size();
   int len2=b.size();
   int len3=c.size();
   for(int i=len1-1;i>=0;i--)
   {
       aa.push(a[i]);
   }
   for(int i=len2-1;i>=0;i--)
   {
       bb.push(b[i]);
   }
   for(int i=len3-1;i>=0;i--)
   {
       cc.push(c[i]);
   }
   char ccc=aa.top();
   while(1)
   {
       //cout<<ccc<<" ";

       if(ccc=='a')
       {
           if(aa.empty())
           {
             cout<<"A";
             break;
          }
           ccc=aa.top();
           aa.pop();
       }
       else if(ccc=='b')
       {
           if(bb.empty())
           {
             cout<<"B";
             break;
           }
           ccc=bb.top();
           bb.pop();
       }
       else if(ccc=='c')
       {
            if(cc.empty())
           {
             cout<<"C";
              break;
           }
           ccc=cc.top();
           cc.pop();
       }

   }
}
