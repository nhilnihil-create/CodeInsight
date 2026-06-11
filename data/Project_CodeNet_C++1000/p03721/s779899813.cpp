#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define vec_input(v) for(auto it=v.begin();it!=v.end();it++){cin>>*it;}
#define vec_output(v) for(auto it=v.begin();it!=v.end();it++){if(it!=v.begin())cout<<" ";cout<<*it;}cout<<endl;
#define vec_debug(v) for(auto it=v.begin();it!=v.end();it++){cerr<<*it<<" ";}cerr<<endl;
#define yn(ans) cout<<(ans?"Yes":"No")<<endl
#define YN(ans) cout<<(ans?"YES":"NO")<<endl
using namespace std;
using ll = long long;
//using map2 = unordered_map;
//using set2 = unordered_set;

//等差数列の和を求める(初項,項数,公差)
long long int arith_sum1(long long int a,long long int n,long long int d){
    return n*(2*a+(n-1)*d)/2;
}
//等差数列の和を求める(初項,末項,項数)
long long int arith_sum2(long long int a,long long int l,long long int n){
    return n*(a+l)/2;
}
//初項1，末項n，項数1の数列の和を求める
long long int series_sum(long long int n){
    return n*(n+1)/2;
}
//各桁の数の和を求める
template <typename T>
T digitsum(T n){
    string s=to_string(n);
    T sum=0;
    T d=1;
    for(T e=0;e<s.length();e++){
        sum+=(n/d)%10;d*=10;
    }
    return sum;
}
template <typename T>
bool isPrime(T n){
    if(n<=1)return false;
    if(n==2||n==3)return true;
    if(n%2==0||n%3==0)return false;
    for(T q=5;q*q<=n;q+=4){
        if(n%q==0)return false;
        q+=2;
        if(n%q==0)return false;
    }
    return true;
}
template <typename T>
vector<pair<T, T>> prime_factor(T n) {
    vector<pair<T, T>> ret;
    T tmp=0;
    if(n%2==0){
        tmp=0;while(n%2==0){tmp++;n/=2;}
        ret.push_back(make_pair(2, tmp));
    }
    if(n%3==0){
        tmp=0;while(n%3==0){tmp++;n/=3;}
        ret.push_back(make_pair(3, tmp));
    }
    for (T i=5;i*i<=n;i+=4) {
        if(n%i==0){
            tmp=0;while(n%i==0){tmp++;n/=i;}
            ret.push_back(make_pair(i,tmp));
        }
        i+=2;
        if(n%i==0){
            tmp=0;while(n%i==0){tmp++;n/=i;}
            ret.push_back(make_pair(i,tmp));
        }
    }
    if(n!=1)ret.push_back(make_pair(n,1));
    return ret;
}
long long int intpow(long long int x,long long int n){
    long long int ans=1;
    for(int i=0;i<n;i++){
        ans*=x;
    }
    return ans;
}
template <typename T>T intlog(T x){
    string a=to_string(x);
    return a.length()-1;
}
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

int main(){
    ll n,k,a,b;
    set<ll> set;
    unordered_map<ll,ll> map;
    cin>>n>>k;
    rep(l,n){
        scanf("%lld %lld",&a,&b);
        if(set.count(a)){
            map[a]+=b;
        }else{
            set.insert(a);
            map[a]=b;
        }
    }
    ll hikaku=0,ans;
    for(auto value:set){
        hikaku+=map[value];
        if(k<=hikaku){
            ans=value;
            break;
        }
    }
    cout<<ans<<endl;
}