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

   vector<int> v(26,0);
   for(char c : s)
    v[c-'a']++;

   for(int index = 0 ;index < 26;index++)
    if(!v[index])
   {
     cout<<(char)('a'+index)<<endl;
       return 0;
   }
   cout<<"None"<<endl;

 return 0;
}
