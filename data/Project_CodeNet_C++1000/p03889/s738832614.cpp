#include<bits/stdc++.h>
#define rr register
#define int long long
#define f_for(i,a,b) for(rr int i=a;i<=b;i++)
using namespace std;
const int maxx=1e4;
int n,m;
string a,b;
signed main(){
    cin>>a;
    b=a;
    bool t=true;
    int len=a.length()-1;
    for(rr int i=0; i<=len; i++)
        switch(a[i]){
            case 'q': a[i]='p';break;
            case 'p': a[i]='q';break;
            case 'b': a[i]='d';break;
            case 'd': a[i]='b';break;
        }
    for(rr int i=0;i<=len;i++)
        if(a[i]!=b[len-i])
            t=false;
    if(t)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
        return 0;
}