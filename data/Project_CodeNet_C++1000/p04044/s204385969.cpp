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
int n,l;
cin>>n>>l;

vector<string> s(n);
for(int index = 0 ;index<n;index++ )
cin>>s[index];

sort(s.begin(),s.end());

for(int index =0 ; index<n;index++)
    cout<<s[index];
cout<<endl;



 return 0;
}
