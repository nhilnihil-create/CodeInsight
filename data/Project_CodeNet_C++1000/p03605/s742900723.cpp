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

while(n)
{
    if(n%10==9)
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    n/=10;
}
cout<<"No"<<endl;

 return 0;
}
