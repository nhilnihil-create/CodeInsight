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
int a , b;
cin>>a>>b;

if(a%3==0||b%3==0||(a+b)%3==0)
    cout<<"Possible"<<endl;
else
    cout<<"Impossible"<<endl;
 return 0;
}
