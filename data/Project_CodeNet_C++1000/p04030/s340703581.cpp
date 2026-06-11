#include<bits/stdc++.h> 
#define ll long long 
#define pb push_back
#define vec vector<int>
#define fo(i, n) for (int i = 0; i < n; i++)
#define so(v) sort(v.begin(), v.end())
#define fi first
#define se second
using namespace std;  

int main()
{
   string s;
    cin>>s;
    stack <char> x;
    vector<char> v ;
    for(ll i=0;i<s.size();i++){
        if(s[i]!='B'){
            x.push(s[i]);
        }
        else{
            if(!x.empty()){
                x.pop();
            }
        }
    }
    
    while(!x.empty()){
        v.push_back(x.top());
        x.pop();
    }

    reverse(v.begin(),v.end());
    for(auto z : v){
        cout<<z;
    }
    return 0;
}



   