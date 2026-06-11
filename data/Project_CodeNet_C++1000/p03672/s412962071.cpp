#include <bits/stdc++.h>
#include <string>
#include <sstream>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define clr(a) memset(a, 0, sizeof(a))
#define set(a) memset(a, -1, sizeof(a))
#define pb push_back
#define sz(a) ((ll)a.size())
#define all(a) a.begin(), a.end()
#define mp make_pair
#define rep(i, a, y) for (ll i = a; i <= y; i++)
#define rep2(i, b) for (int i = 0; i < b; i++)
#define repl(i, a, b) for (ll i = a; i <= b; i++)
#define ppi pair<int, int>
#define scl(x) scanf("%d", &x)
#define pcl(x) printf("%d", x)
#define FastRead                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
/*
 
     ██╗██╗   ██╗██╗  ██╗ █████╗ ███╗   ██╗
     ██║██║   ██║██║  ██║██╔══██╗████╗  ██║
     ██║██║   ██║███████║███████║██╔██╗ ██║
██   ██║██║   ██║██╔══██║██╔══██║██║╚██╗██║
╚█████╔╝╚██████╔╝██║  ██║██║  ██║██║ ╚████║
 ╚════╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝
 
*/
//map<char, ll> p;
//map<char, ll>::iterator it;
// bool solve(string ans)
// {
//     //string str=r;
//     for(ll i=0;i<sz(r);i++) 
//     {
//         p[r[i]]++;
//     }
//     for(it=p.begin();it!=p.end();it++) 
//     {
//         if(it->second%2!=0) 
//         {
//             return false;
//         }
//     }
//     return true;
// }
bool solve(string str)
{
    ll arr[26];
    memset(arr,0,sizeof(arr));
    for(ll i=0; i<sz(str); ++i)
    {
        ll id=(int)str[i]-97;
        arr[id]=arr[id]+1;
    }
    for(ll i=0; i<26; ++i)
    {
        if(arr[i]%2!=0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    bool cnt=0;
    FastRead;
    string s;
    cin >> s;
    for (ll i =sz(s)-1;i>=0; i--)
    {
        string x=s.substr(0,i);
        if(solve(x))
        {
            string z="",y="";
            for(ll j=0;j<sz(x)/2;j++) z+=x[j];
            for(ll j=sz(x)/2;j<sz(x);j++) y+=x[j];
            if(z==y)
            {
                cout<<sz(x)<<endl;
                return 0;
            }
        }
    }
    cout<<"0"<<endl;
    return 0;
    // ll test=1;
    // //cin>>test;
    // while(test--)
    // {
    //     string str;
    //     cin>>str;
    //     for(ll i=sz(str)-1; i>=0; --i)
    //     {
    //         string ans=str.substr(0,i);
    //         if(solve(ans))
    //         {
    //             if(ans.substr(0,sz(ans)/2LL)==ans.substr(sz(ans)/2LL,sz(ans)/2LL))
    //             {
    //                 cout<<sz(ans)<<endl;
    //                 return 0;
    //             }
    //         }
    //     }
    //     cout<<0<<endl;
    // }
    // return 0;
}