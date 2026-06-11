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
    const ll inf=1e9+7;
    const ll INF=1e18;
     
    int main(){
        ll n,W;cin>>n>>W;
        vvll wei(4);
        rep(i,4)wei[i].push_back(inf);
        ll w,v,tmp;cin>>w>>v;
        tmp=w;wei[0].push_back(v);
        rep(i,n-1){
            cin>>w>>v;
            wei[w-tmp].push_back(v);
        }
        rep(i,4){
            sort(all(wei[i]));
            reverse(all(wei[i]));
            wei[i][0]=0;
        }
        rep(i,4)rep(j,wei[i].size()-1)wei[i][j+1]+=wei[i][j];
        ll ans=0;
        rep(i,wei[0].size())rep(j,wei[1].size())rep(k,wei[2].size())rep(l,wei[3].size()){
            if((i+j+k+l)*tmp+j+2*k+3*l<=W){
                ans=max(ans,wei[0][i]+wei[1][j]+wei[2][k]+wei[3][l]);
            }
        }
        cout<<ans<<endl;
    }