
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
#define vec(s) vector<s>;
#define vvec(s) vector<vector<s>> ;
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<lli,lli> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YN(x) cout<<(bool x?"Yes":"No")<<endl;
#define out(s) cout<<s<<endl;
#define pb(s) push_back(s);
#define sp " ";
#define INF 10000000000
#define all(s) s.begin(),s.end()
void vout(vector<int> v){
    for(int i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;
}
int main(){
    lli n;
    cin>>n;
    lli i=1;
    vi fr,ba;
    while(i<=n){
        lli a;
        cin>>a;
        if(i%2==1){
            ba.push_back(a);
        }
        else{
            fr.push_back(a);
        }
        i++;
    }
    if(n%2==1){
        reverse(all(ba));
        rep(i,ba.size()){
            cout<<ba[i]<<" ";
        }
        rep(i,fr.size()){
            cout<<fr[i];
            if(i==fr.size()-1){
                cout<<endl;
            }
            else{
                cout<<" ";
            }
        }
    }
    else{
        reverse(all(fr));
        rep(i,fr.size()){
            cout<<fr[i]<<" ";
        }
        rep(i,ba.size()){
            cout<<ba[i];
            if(i==ba.size()-1){
                cout<<endl;
            }
            else{
                cout<<" ";
            }
        }
    }
}