#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    string s;
    cin>>s;

    reverse(all(s));
    int n=s.size();

    string a="maerd";
    string b="remaerd";
    string c="esare";
    string d="resare";

    int id=0;
    while(id<n){
        bool ok1=true,ok2=true,ok3=true,ok4=true;
        rep(i,a.size()){
            if(s[id+i]!=a[i]) ok1=false;
        }
        rep(i,b.size()){
            if(s[id+i]!=b[i]) ok2=false;
        }
        rep(i,c.size()){
            if(s[id+i]!=c[i]) ok3=false;
        }
        rep(i,d.size()){
            if(s[id+i]!=d[i]) ok4=false;
        }

        if(ok1) id+=a.size();
        else if(ok2) id+=b.size();
        else if(ok3) id+=c.size();
        else if(ok4) id+=d.size();
        else{
            cout<<"NO"<<endl;
            return 0;
        }
        
        if(id==n){
            cout<<"YES"<<endl;
            return 0;
        }
    }

    cout<<"NO"<<endl;
}
