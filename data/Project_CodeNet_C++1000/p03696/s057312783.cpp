#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(inti=a;i<=b;i++)

#define MOD 1000000009
typedef long long int ll;
typedef vector<int>vi;
typedef pair<int,int>pi;


int main()
{
    int n ;
    cin>>n;
    string s;
    cin>>s;
int open =0,close =0;

for(int index=0;index<n;index++)
{
    if(s[index]=='(')
        open++;
    else
    {
        if(open)open--;
        else
            close++;
    }
}
while(close--)
    cout<<'(';
cout<<s;
while(open--)
    cout<<')';
cout<<endl;
 return 0;
}
