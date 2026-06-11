#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    char ar[1000];
    ar['a']=0;ar['b']=0;ar['c']=0;ar['d']=0;ar['e']=0;ar['f']=0;ar['g']=0;ar['h']=0;ar['i']=0;
    ar['j']=0;ar['k']=0;ar['l']=0;ar['m']=0;ar['n']=0;ar['o']=0;ar['p']=0;ar['q']=0;ar['r']=0;
    ar['s']=0;ar['t']=0;ar['u']=0;ar['v']=0;ar['w']=0;ar['x']=0;ar['y']=0;ar['z']=0;

    string a;
    cin>>a;

    int length,i;
    length=a.length();

    for(i=0;i<length;i++)
    {
       ar[a[i]]++;
    }

if((ar['a']==0||ar['a']%2==0)&&(ar['b']==0||ar['b']%2==0)&&(ar['c']==0||ar['c']%2==0)&&(ar['d']==0||ar['d']%2==0)
&&(ar['e']==0||ar['e']%2==0)&&(ar['f']==0||ar['f']%2==0)&&(ar['g']==0||ar['g']%2==0)&&(ar['h']==0||ar['h']%2==0)
&&(ar['i']==0||ar['i']%2==0)&&(ar['j']==0||ar['j']%2==0)&&(ar['k']==0||ar['k']%2==0)&&(ar['l']==0||ar['l']%2==0)
&&(ar['m']==0||ar['m']%2==0)&&(ar['n']==0||ar['n']%2==0)&&(ar['o']==0||ar['o']%2==0)&&(ar['p']==0||ar['p']%2==0)
&&(ar['q']==0||ar['q']%2==0)&&(ar['r']==0||ar['r']%2==0)&&(ar['s']==0||ar['s']%2==0)&&(ar['t']==0||ar['t']%2==0)
&&(ar['u']==0||ar['u']%2==0)&&(ar['v']==0||ar['v']%2==0)&&(ar['w']==0||ar['w']%2==0)&&(ar['x']==0||ar['x']%2==0)
&&(ar['y']==0||ar['y']%2==0)&&(ar['z']==0||ar['z']%2==0))
{
    cout<<"Yes"<<endl;
}
else
{
    cout<<"No"<<endl;
}






return 0;
}
