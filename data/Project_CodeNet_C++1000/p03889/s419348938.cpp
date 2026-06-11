#include<iostream> 
#include<stdio.h>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;
string a;
char p[300];
int b=1,q;
void init()
{
    p['b'] = 'd';
    p['d'] = 'b';
    p['q'] = 'p';
    p['p'] = 'q';
}
int main()
{
    getline(cin,a);
    init();
    for(int i=0;i<=a.size()-1;i++)
    {
        if(p[a[i]]!=a[a.size()-1-i])
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}