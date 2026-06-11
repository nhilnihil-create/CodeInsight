#include <bits/stdc++.h>
using namespace std;
struct P
{
    //string r;
    int x,y,z;

    bool operator<(const P &a)const{
       // if(y!=a.y)
       // return y>a.y;
       return x<a.x;
//        return z>a.z;
    }
};

vector<int> v[100055];
//bitset<4001000> b;
int a,c,i,b,k,d,n,m,e;//dy[15]={0,1,0,-1,-1,1,-1,1},dx[15]={1,0,-1,0,1,1,-1,-1};//
int l[110515];
int o[100510];
int dx[10]={0,1,0,-1},dy[10]={1,0,-1,0},dz[10]={0,0,0,0,1,-1};

long long x,y,z,mod=1000000007;
P u[11];
int j[55];

stack<int> s;
queue<int> q;

//'1'==49;
//'A'==65;
//'a'==97;
//unordered_
//map<int,int > p;
//list<int> l;
//string r[111],r2;
char r[510][555];


bool as(P a,P b)
{
   // if(a.x!=b.x)
        return a.x<b.x;
    //return a.y>b.y;
}

int f(int a)
{
    if(!v[a].size()) return 1;
    if(l[a]>=0) return l[a];
    for(int h=0;h<v[a].size();h++)
        l[a]=max(l[a],f(v[a][h])+1);
    if(l[a]>=b&&o[a]!=1) k++,l[a]=0;
    return l[a];
}

int main()
{
    scanf("%d %d",&a,&b);
    memset(l,-1,sizeof(l));
    for(int t=1;t<=a;t++)
        scanf("%d",&o[t]);
    if(o[1]!=1) k++,o[1]=1;
    for(int t=1;t<=a;t++)
        v[o[t]].push_back(t);
    
    for(int t=2;t<=a;t++)
    if(b>1)
    {
        l[t]=f(t);
        //printf("%d ",l[t]);
        //if(o[t]>1)
        //if(b==1||!l[t]%b) k++;
    }
    else if(o[t]>1) k++;
    //for(int t=1;t<=a;t++)
    //printf("%d ",l[t]);
    printf("%d",k);

}
