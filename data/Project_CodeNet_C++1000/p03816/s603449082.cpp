#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register
#define Maxn 100010
#define INF 10010
inline int read()
{
    char c=getchar();re ll f=1,s=0;
    while(!isdigit(c)){if(c=='-')f=-1,c=getchar();}
    while(isdigit(c)){s=s*10+c-48;c=getchar();}
    return f*s;
}
map<int,int> m;
int n,x,s;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>x;
    	if(m[x]) s++;
    	else m[x]++; 
    }
    if(s&1) s++;
    cout<<n-s<<endl;
    return 0;
}     