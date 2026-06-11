#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;
const ll INF = 1061109567;
const double EPS = 1e-10;
int main(){

    map<char,int> a;
    char s;
    while(cin>>s){
        a[s]++;
    }
    for(auto i=a.begin();i!=a.end();i++){
        if(i->second%2!=0){
            cout<<"No"<<endl;
            return 0;
        }
        
    }
    cout<<"Yes"<<endl;
    return 0;
}
