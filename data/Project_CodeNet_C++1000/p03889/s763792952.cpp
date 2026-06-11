//这是我见过的几乎最水的紫题qwq
#include<bits/stdc++.h>
using namespace std;
int t=1;
string a,b;
int main()
{
    cin>>a, b=a;
    for(int i=0;i<=a.length()-1;i++) switch(a[i])
    {
        case 'q': a[i]='p'; break;
        case 'p': a[i]='q'; break;
        case 'b': a[i]='d'; break;
        case 'd': a[i]='b'; break;
    }
    for(int i=0;i<=a.length()-1;i++) if(a[i]!=b[a.length()-1-i]) t=0;
    if(t) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
