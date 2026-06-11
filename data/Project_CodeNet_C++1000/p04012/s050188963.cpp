#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define  optimize   ios::sync_with_stdio(0); cin.tie(0);
#define PI  acos(-1.0)
#define RESET(a, b) memset(a, b, sizeof(a))
#define pb push_back
int main()
{
     optimize
     string s;
     cin>>s;
     int n=s.length();
     map<char,int>Map;
     for(int i=0;i<n;i++){
        Map[s[i]]++;
     }
     for(char i='a';i<='z';i++){
        if(Map[i]%2){
            cout<<"No\n";
            return 0;
        }
     }
     cout<<"Yes\n";
}
