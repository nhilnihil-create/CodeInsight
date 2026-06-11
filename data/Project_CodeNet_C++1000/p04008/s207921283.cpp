#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<class F>auto recursive(F f){return[f](auto...a){return f(f,a...);};}
template<class I,class V=typename I::value_type>V sum_up(const I&l,const I&r){V v;for(I i=l;i!=r;i++)v=i==l?*i:v+*i;return v;}
template<class I,class T=iterator_traits<I>>I operator+(I it,int n){for(int i=0;i<n;i++)it++;return it;}
template<class I,class T=iterator_traits<I>>I operator-(I it,int n){for(int i=0;i<n;i++)it--;return it;}
template<class T>using rev_priority_queue=priority_queue<T,vector<T>,greater<T>>;
template<class T>using vector2d=vector<vector<T>>;
struct fixprec{int p;fixprec(int p):p(p){}};
ostream&operator<<(ostream&o,fixprec f){return o<<fixed<<setprecision(f.p);}
void R_YESNO(bool p){cout<<(p?"YES":"NO")<<endl;}
void R_YesNo(bool p){cout<<(p?"Yes":"No")<<endl;}
/*!* [minmax_assign] *!*/
/*+* 最大値、最小値の代入 *+*/
template<class T>void max_assign(T&x,const T y){x=max(x,y);}
template<class T>void min_assign(T&x,const T y){x=min(x,y);}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    vector2d<int> edge(N);
    int ans = 0;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
        if(i == 0) {
            if(a[i] != 0) ans++;
            a[i] = 0;
        } else {
            edge[a[i]].push_back(i);
        }
    }

    recursive([&](auto f, int i) -> int {
        int dep = 0;
        for(int j : edge[i]) {
            max_assign(dep, f(f, j));
        }
        if (a[i] != 0 && dep >= K - 1) {
            ans++;
            return 0;
        }
        return dep + 1;
    })(0);
    cout << ans << endl;
    return 0;
}

