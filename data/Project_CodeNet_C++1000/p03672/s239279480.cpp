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


int check(string s )
{
    //cout<<s<<endl;
    int n =s.size();
    if(n%2==0&&s.substr(0,n/2)==s.substr(n/2))
    return n/2;
    return -1;

}
int main()
{
string s ;
cin>>s;



int n = s.size();
int f;
int index =0;
do
{
     f= check(s.substr(0,n-index-1));
index++;
}while( f==-1);
cout<<2*f<<endl;
 return 0;
}
