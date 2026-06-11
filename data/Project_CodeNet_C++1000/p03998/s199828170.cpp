#include<bits/stdc++.h>
//#include<iostream>

//#include<vector>
//#include<iterator>
//#include<utility>
//#include<algorithm>
//#include<cmath>
using namespace std;


#define ll long long
#define fr(m) for(int i=0; i<m; i++)
#define frj(m) for(int j=0; j<m; j++)
#define frr(n) for(int i=n; i>=0; i--)
#define pb push_back
#define orr ||
#define nl \n
#define sci(n) scanf("%lld ", &n)
#define pri(n) printf("%d", n)
#define prl(n) printf("%lld", n)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl


int main()
{

    deque<char> de1,de2,de3;
    string a,b,c;
    cin>>a>>b>>c;
    for(char d: a){
        de1.pb(d);
    }
    for(char d: b){
        de2.pb(d);
    }
    for(char d: c){
        de3.pb(d);
    }
    char current=de1.front(),ans;
    while(!de1.empty() orr !de2.empty() orr !de3.empty()){
        if(current=='a'){
            if(de1.empty()){
                ans='A';
                break;
            }
            current=de1.front();
            de1.pop_front();

        }
        else if(current=='b'){
            if(de2.empty()){
                ans='B';
                break;
            }
            current=de2.front();
            de2.pop_front();

        }
        else{
            if(de3.empty()){
                ans='C';
                break;
            }
            current=de3.front();
            de3.pop_front();

        }
    }
    cout<<ans<<endl;
    return 0;
}
