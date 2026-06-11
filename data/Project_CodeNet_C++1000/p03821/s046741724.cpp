#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i,n) for (int i=0;i<(int)(n);i++)
#define codefor int test;scanf("%d",&test);while(test--)
#define yn(ans) cout<<(ans?"Yes":"No")<<endl
#define YN(ans) cout<<(ans?"YES":"NO")<<endl
#define umap unordered_map
#define uset unordered_set
using namespace std;
using ll = long long;
const int MOD=1000000007;
//入力系
void scan(int& a){scanf("%d",&a);}
void scan(long long& a){scanf("%lld",&a);}
template<class T> void scan(T& a){cin>>a;}
template<class T> void scan(vector<T>& vec){for(auto&& it:vec)scan(it);}
void in(){}
template <class Head, class... Tail> void in(Head& head, Tail&... tail){scan(head);in(tail...);}
//出力系
void print(const int& a){printf("%d",a);}
void print(const long long& a){printf("%lld",a);}
void print(const double& a){printf("%.15lf",a);}
template<class T> void print(const T& a){cout<<a;}
template<class T> void print(const vector<T>& vec){if(vec.empty())return;print(vec[0]);for(auto it=vec.begin();++it!= vec.end();){putchar(' ');print(*it);}}
void out(){putchar('\n');}
template<class T> void out(const T& t){print(t);putchar('\n');}
template <class Head, class... Tail> void out(const Head& head,const Tail&... tail){print(head);putchar(' ');out(tail...);}
//デバッグ系
template<class T> void dprint(const T& a){cerr<<a;}
template<class T> void dprint(const vector<T>& vec){if(vec.empty())return;cerr<<vec[0];for(auto it=vec.begin();++it!= vec.end();){cerr<<" "<<*it;}}
void debug(){cerr<<endl;}
template<class T> void debug(const T& t){dprint(t);cerr<<endl;}
template <class Head, class... Tail> void debug(const Head& head, const Tail&... tail){dprint(head);cerr<<" ";debug(tail...);}

long long int combination(long long int a,long long int b){
    queue<long long int> bunsi,bunbo;
    long long int ans=1;
    b=min(b,a-b);
    for(int i=0;i<b;i++){
        bunsi.push(a-i);
        if(b-i>=2)bunbo.push(b-i);
    }
    while(bunsi.size()!=0||bunbo.size()!=0){
        ans*=bunsi.front();
        bunsi.pop();
        if(ans%bunbo.front()==0){
            ans/=bunbo.front();
            bunbo.pop();
        }
    }
    return ans;
}

bool one (int i) {
    if(i>=1)return true;
    else return false;
}

int main(){
    int n;
    in(n);
    int a,b;
    vector<pair<int,int>> vec(n);
    rep(i,n){
        in(a,b);
        vec[i]=make_pair(a,b);
    }
    ll ans=0;
    reverse(all(vec));
    rep(i,n){
        if((vec[i].first+ans)%vec[i].second!=0){
            ans+=(ll)vec[i].second-((ll)vec[i].first+ans)%((ll)vec[i].second);
        }
    }
    out(ans);
}