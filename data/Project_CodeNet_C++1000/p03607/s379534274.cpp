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
map<int,int> v;
while(n--)
{
    int a ;
    cin>>a;

    if(!v[a])
        v[a]++;
    else
        v[a]--;
    }


int ans =0;
for(auto it = v.begin();it!=v.end();it++)
{
    //cout<<it->first<< " "<<it->second<<endl;
    if(it->second)
    ans++;
}


    cout<<ans<<endl;

 return 0;
}
