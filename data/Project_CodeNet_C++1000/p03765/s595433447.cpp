#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <numeric>
#include <utility>
#define sign(a) ((a>0)-(a<0))
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define LL long long
#define INF (LL)(1LL<<60)
#define all(a) a.begin(), a.end()
#define gr greater<LL>()

using namespace std;

template <class T>
class SegTree{
public:
    vector<T> arr;
    function<T(T,T)> f;
    T ini;
    uint n;
    SegTree(int N, function<T(T,T)> func, T ini_){
        f=func;
        ini=ini_;
        n=1;
        while(n<N)n<<=1u;
        arr.assign(2*n-1, ini);
    }

    void update(uint i, T val){
        i+=n-1;
        arr[i]=val;
        while(i>0){
            i=(i-1)/2;
            arr[i]=f(arr[2*i+1],arr[2*i+2]);
        }
    }

    T find(uint s, uint t){
        return __find(s,t,0,0,n);
    }
private:
    T __find(uint s, uint t, uint k, uint l, uint r){
        if(t<=l || s>=r)return ini;
        if(s<=l && t>=r)return arr[k];
        T vl=__find(s,t,2*k+1,l,(l+r)/2);
        T vr=__find(s,t,2*k+2, (l+r)/2, r);
        return f(vl,vr);
    }
};

const string YES = "YES";
const string NO = "NO";

void solve(std::string S, std::string T, long long q, std::vector<long long> a, std::vector<long long> b, std::vector<long long> c, std::vector<long long> d){
    auto f = [](char c1, char c2){
        string s={c1, c2};
        sort(all(s));
        if(s[0]==' ')return s[1];
        if(s=="AB")return ' ';
        if(s=="AA")return 'B';
        if(s=="BB")return 'A';
        throw 0;
    };

    int ns=S.length(), nt=T.length();
    SegTree<char> sts(ns, f, ' '), stt(nt, f, ' ');
    rep(i,ns)sts.update(i,S[i]);
    rep(i,nt)stt.update(i,T[i]);
    rep(i,q){
        cout << (sts.find(a[i]-1,b[i])==stt.find(c[i]-1,d[i]) ? YES : NO) << endl;
    }
}

int main(){
    std::string S;
    std::cin >> S;
    std::string T;
    std::cin >> T;
    long long q;
    scanf("%lld",&q);
    std::vector<long long> a(q);
    std::vector<long long> b(q);
    std::vector<long long> c(q);
    std::vector<long long> d(q);
    for(int i = 0 ; i < q ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
        scanf("%lld",&c[i]);
        scanf("%lld",&d[i]);
    }
    solve(S, T, q, std::move(a), std::move(b), std::move(c), std::move(d));
    return 0;
}
