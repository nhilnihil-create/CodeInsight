#include<bits/stdc++.h>
using namespace std;


//defines...
#define ll long long
#define tata return;
#define pb push_back
#define mp make_pair
#define in insert
#define run ios_base::sync_with_stdio(false);cin.tie(NULL);
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define vec vector<ll>
#define setl set<ll>
#define mapl map<ll,ll>
#define shunno cout<<0<<endl;
#define pi 2*acos(0.0)1
#define hobena cout<<-1<<endl;







void oka()
{
    ll a,b;
    cin>>a>>b;
    multimap<string,string>m;
    while(a--)
    {
        string s;
        cin>>s;
        m.insert(pair<string,string>(s,s));
    }
    multimap<string,string>::iterator it;
    for(it=m.begin();it!=m.end();it++)
        cout<<it->second;
    cout<<endl;




}






int main()
{

   //string g="abcd";
    //g.erase(g.begin()+3);
    //cout<<g<<endl;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    run
    ll i,t;
    t=1;
  // cin>>t;


    for(i=1;i<=t;i++)
    {


    oka();
    }






}