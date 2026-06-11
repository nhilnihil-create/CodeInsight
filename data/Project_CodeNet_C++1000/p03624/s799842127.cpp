#include<bits/stdc++.h>
using namespace std;
#define int            int64_t
#define double         long double
#define nitro          ios_base::sync_with_stdio(false);cin.tie(0);
#define vi             vector<int64_t>
#define pub            push_back
#define puf            push_front
#define pob            pop_back
#define pof            pop_front
#define PI             3.1415926535897932384626433832795
#define read(a)        for(auto& x : a) cin>> x
#define endl           '\n'
#define gap            ' '
#define min3(a,b,c)    min(a, min(b, c))
#define max3(a,b,c)    max(a, max(b, c))
#define MOD            1000000007
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
int a[26];
int32_t main()
{
    nitro
    string s,s1;cin>>s;
    for(char c:s) a[c-'a']++;
    for(int i=0;i<26;i++){
    	if(a[i]==0) s1+=(char)(i+97);
    }
    if(s1.size()==0) cout<<"None";
    else cout<<s1.front();
   
}
    