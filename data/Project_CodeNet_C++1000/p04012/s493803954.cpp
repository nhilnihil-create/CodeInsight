#include<iostream>
#include<map>
#define int long long
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define line cout<<"here - "<<__LINE__<<"\n";
#define dbg(a) cout<<#a<<" --> "<<(a)<<"\n";
#define infi INT_MAX
#define rinfi INT_MIN
#define inf LLONG_MAX
#define rinf LLONG_MIN
#define ff first
#define ss second
using namespace std;
main()
{
    //fast
    int tc=1,i,j,k;
//    cin>>tc;
    while(tc--)
    {
       string aa;
       cin>>aa;
       map<char,int>mp;
       for(i=0;i<aa.size();i++)
        mp[aa[i]]++;
       int ok=1;
       for(char s='a';s<='z';s++)
       {
           if(mp[s]%2==1)
            ok=0;
       }
       if(ok) cout<<"Yes"<<endl;
       else cout<<"No"<<endl;

    }
}


