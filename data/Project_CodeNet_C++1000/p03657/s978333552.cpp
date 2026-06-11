#include<bits/stdc++.h>

using namespace std;
#define ll  long long
#define ld  long double

#define endl '\n'
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll mod = 1000000007;
const double PI = 3.141592653589793238463;

int freq[26];
bool vis[26];
int main()
{
   int a,b;
   cin>>a>>b;
   if((a+b)%3==0 || a%3==0 || b%3==0)
    cout<<"Possible"<<endl;
   else
    cout<<"Impossible"<<endl;



    return 0;
}
