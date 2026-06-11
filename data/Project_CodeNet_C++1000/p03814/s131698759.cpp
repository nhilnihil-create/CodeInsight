    #include<bits/stdc++.h>
    using namespace std;
    #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define REP(i,x) for(int i=0;i<(int)(x);i++)
    #define REPS(i,x) for(int i=1;i<=(int)(x);i++)
    #define mp(a,b) make_pair(a, b)
    #define pb push_back
    #define eb emplace_back
    #define ll long long
    #define MAX 10000000
    int main()
    { string s;
    vector<int>v,v1;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
       if(s[i]=='Z') v.pb(i);
       if(s[i]=='A') v1.pb(i);
    }
    int p=v[v.size()-1]-v1[0];
    cout<<p+1<<endl;
    
    }