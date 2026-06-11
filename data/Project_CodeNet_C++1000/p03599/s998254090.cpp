#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const int inf=1e9+7;
const ll INF=1e18;

int main(){
    int a,b,c,d,e,f;cin>>a>>b>>c>>d>>e>>f;
    double Max=-1;
    int water,tmp,ans1,ans2;
    bool can;
    rep(i,f/(100*a)+1)for(int j=0;100*a*i+100*b*j<=f;j++){
        water=100*a*i+100*b*j;
        tmp=min(-water+f,e*water/100);
        can=false;
        for(int sugar=tmp;sugar>=0;sugar--){
            rep(k,sugar/c+1){
                if((sugar-c*k)%d==0){
                    can=true;
                    break;
                }
            }
            if(can&&Max<(double)sugar/(double)(water+sugar)){
                Max=(double)sugar/(double)(water+sugar);
                ans1=water+sugar;
                ans2=sugar;
                break;
            }
        }
    }
    cout<<ans1<<" "<<ans2<<endl;
}