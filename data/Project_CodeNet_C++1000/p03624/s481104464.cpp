//Radhe Radhe
#include<bits/stdc++.h>
#define godspeed  ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define ll long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define rep1(i,a,b)    for(ll i=a; i<=b; i++)
#define repVect(i,n)    for(ll i=0; i<sum.size(); i++)
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(7);
#define yes cout<<"Yes"<<'\n';
#define no cout<<"No"<<'\n';
using namespace std;

int main()
{
    godspeed
    ll  t,i,x,j,k,n,a,b,c,d,alp[26]={0};
    string s;
    cin>>s;
    for(i=0;s[i];i++)
    {
    x=s[i]-'a';
    alp[x]=1;
    }
    for(i=0;i<26;i++)
    {
        if(alp[i]==0){
            char c='a'+i;
       return cout<<c<<endl,0;
        }
    }
     cout<<"None"<<endl;

    return 0;
}



