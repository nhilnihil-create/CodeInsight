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
string s ;
cin>>s;

int n = s.size();
for(int index = 0 ;index < n;index++)
    if(s[index]!=s[n-index-1])
{
    cout<<"No"<<endl;
    return 0;
}
cout<<"Yes"<<endl;
 return 0;
}
