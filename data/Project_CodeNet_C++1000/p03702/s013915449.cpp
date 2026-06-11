#include<bits/stdc++.h>
using ll  = long long;
#define int ll
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,s,n) for(int i=s;i<n;i++)
#define erep(e,v) for(auto && e :v)
#define all(in) in.begin(), in.end()
#define MP make_pair
#define INF (sizeof(int) == 4 ? (int)1e9:(int)1e18)
#define EPS 0.0000000001
using namespace std;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<typename Head, typename Value> auto vectors(const Head &head, const Value &v) { return vector<Value>(head, v); }
template<typename Head, typename... Tail> auto vectors(Head x, Tail... tail) { auto inner = vectors(tail...); return vector<decltype(inner)>(x, inner); }
template<class T> void join(T a){for(auto itr :a){if(itr != *a.begin())cout << " "; cout << itr;} }
using ld  = long double;
using pii = pair<int,int>;
using piii = pair<int,pii>;
int W,H;
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
bool valid(int x,int y){return (0<=x&&x<W)&&(0<=y&&y<H);}
template<class F>
auto  minimize_bsearch(int imin,int imax,F &f){ //(imin,imax]
    /*
     return minimum index such that v[index] >= value
     auto f(int mid) {return v[mid] >= value;}
     */
    while(imax - imin > 1){
        int mid = imin + (imax - imin)/2;
        if(f(mid)) imax = mid;
        else imin = mid;
    }
    return imax; //imax is ans
}

template<class F>
auto  maximize_bsearch(int imin,int imax,F &f){ //[imin,imax)
    /*
     return maximum index such that v[index] <= value
     auto f(int mid) {return v[mid] <= value;}
     */
    while(imax - imin > 1){
        int mid = imin + (imax - imin)/2;
        if(f(mid)) imin = mid;
        else imax = mid;
    }
    return imin; //imin is ans
}
signed main(){
    int n,A,B;
    cin >> n >> A >> B;
    vector<int>h(n);
    for(auto  & e  : h) cin >> e;
    sort(all(h),greater<>());
    function<bool(int)>comp = [&](int mid) -> bool{
        int margin = (A - B) * mid;
        for(auto e : h){
            if(e  <= B*mid){
                
            } else {
                int dif = e - B*mid;
                margin -= (dif/(A-B) + (dif % (A-B) ? 1:0)) * (A-B);
                if(margin < 0 )return false;
            }
        }
        return true;
    };
    cout << minimize_bsearch(0,1000000000, comp) << endl;
}

