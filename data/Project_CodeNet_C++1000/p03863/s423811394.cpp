#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) ((int)(x).size())
#define int long long
using namespace std;
typedef vector<int>   vint;
typedef pair<int,int> pint;

signed main()
{
    string s; cin>>s;
    if(s[0]==s.back()){
        if(SZ(s)%2==0) cout<<"First"<<endl;
        else cout<<"Second"<<endl;
    }
    else{
        if(SZ(s)%2==0) cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }
}
