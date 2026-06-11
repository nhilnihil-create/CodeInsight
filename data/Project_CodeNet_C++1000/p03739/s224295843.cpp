#include <bits/stdc++.h>
#define rep(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define int long long
using namespace std;
using P=pair<int,int>;
using Graph=vector<vector<int>>;
using ll=long long;


ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}
bool root(string s){
    int n=s.length();
    if(n==2){
        if(s[0]==s[1]){
            return true;
        }
        else return false;
    }
    if(n==3){
        if(s[0]==s[2]){
            return true;
        }
        else return false;
    }
 
    return false;
}
bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

//深さ優先
vector<int> seen;
vector<ll> h;
 
//普通の深さ優先探索seenを返す感じ
void dfs(const Graph &G,int v){

    seen[v] = 0; //v探索済み
 
    P good=make_pair(v,h[v]);
    for(auto next_v :G[v]){
        if(seen[next_v]!=-1) continue;//もう探索していた
        if(h[next_v]>good.second){
            good=make_pair(next_v,h[next_v]);
        }
        dfs(G,next_v);
    }
 
    if(!(h[v]==good.second && v==good.first)){
        seen[good.first]=1;
    }
}


int n;

void dfs(string s, char mx){
    if(s.length()==n){
        cout<<s<<endl;
    }else{
        for(char c='a';c<=mx;c++){
            dfs(s+c,((c==mx) ? (char)(mx+1) : mx));
        }
    }
}


signed main(){ 
    int n;
    cin>>n;
    int a[n];
    rep(i,0,n) cin>>a[i];

    int pl,mi;

    //正始まり
    {
        int ans=0;
        int sum[n];
        if(a[0]<=0){
            ans+=abs(a[0])+1;
            sum[0]=1;
        }else sum[0]=a[0];
        bool pred=true;
        for(int i=1;i<n;i++){
            if(sum[i-1]+a[i]==0){
                ans++;
                if(pred){
                    sum[i]=-1;
                    pred=!pred;
                }else{
                    sum[i]=1;
                    pred=!pred;
                }
            }else{
                if(pred!=(sum[i-1]+a[i]>0)){
                    sum[i]=sum[i-1]+a[i];
                    pred=!pred;
                }else{
                    if(sum[i-1]+a[i]>0){
                        sum[i]=-1;
                    }else sum[i]=1;
                    
                    ans+=abs(sum[i-1]+a[i])+1;
                    pred=!pred;
                }
            }
        }
        pl=ans;
    }
    
    //負始まり
    {
        int ans=0;
        int sum[n];
        if(a[0]>=0){
            ans+=abs(a[0])+1;
            sum[0]=-1;
        }else sum[0]=a[0];
        bool pred=false;
        for(int i=1;i<n;i++){
            if(sum[i-1]+a[i]==0){
                ans++;
                if(pred){
                    sum[i]=-1;
                    pred=!pred;
                }else{
                    sum[i]=1;
                    pred=!pred;
                }
            }else{
                if(pred!=(sum[i-1]+a[i]>0)){
                    sum[i]=sum[i-1]+a[i];
                    pred=!pred;
                }else{
                    if(sum[i-1]+a[i]>0){
                        sum[i]=-1;
                    }else sum[i]=1;
                    
                    ans+=abs(sum[i-1]+a[i])+1;
                    pred=!pred;
                }
            }
        }
        mi=ans;
    }

    

    cout<<min(pl,mi)<<endl;
}  