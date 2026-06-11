#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define inf 1000000000
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define meM(y,a) memset(y,a,sizeof y)
#define sC(a) scanf("%d",&a)
#define alL(a) a.begin(),a.end()
#define prinT(a,sz)  cout<<a[0];for(int i=1;i<sz;i++)cout<<" "<<a[i];cout<<endl
#define ranD srand(chrono::steady_clock::now().time_since_epoch().count());
typedef pair<int,int>pi;
typedef pair<ll,ll>pll;
//int fx[]={0,0,1,-1};
//int fy[]={1,-1,0,0};
//int gx[]={0,0,1,1,1,-1,-1,-1};
//int gy[]={1,-1,0,1,-1,0,1,-1};
const int N=100010;

int main()
{
    IOS;
    while(1)
    {
        string s;
        cin>>s;
        int k;cin>>k;
        int l=s.length();
        for(int i=0;i<l;i++){
            if(s[i]+k>'z'&&s[i]!='a'){
                int temp=('z'-s[i]+1);
                k-=temp;
//                cout<<i<<" "<<temp<<endl;
                s[i]='a';
            }
        }
//        cout<<"k = "<<k<<endl;
        k%=26;
        for(int i=0;i<k;i++)
        {
            if(s[l-1]=='z')s[l-1]='a';
            else s[l-1]++;
        }
        cout<<s<<endl;
        break;
    }
}
/*
awe
26
*/
