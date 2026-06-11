#include<bits/stdc++.h>
using namespace std;
#define INFS (1LL<<28)
#define INF (1LL<<60)
#define DEKAI 1000000007
//#define MOD 1000000007
#define lp(i,n) for(int i=0;i<n;i++)
#define lps(i,n) for(int i=1;i<=n;i++)
#define all(c) begin(c), end(c)

//#define int long long 

namespace {
#define __DECLARE__(C)    \
    template <typename T> \
    std::ostream &operator<<(std::ostream &, const C<T> &);

#define __DECLAREM__(C)               \
    template <typename T, typename U> \
    std::ostream &operator<<(std::ostream &, const C<T, U> &);

__DECLARE__(std::vector)
__DECLARE__(std::deque)
__DECLARE__(std::set)
__DECLARE__(std::stack)
__DECLARE__(std::queue)
__DECLARE__(std::priority_queue)
__DECLARE__(std::unordered_set)
__DECLAREM__(std::map)
__DECLAREM__(std::unordered_map)

template <typename T, typename U>
std::ostream &operator<<(std::ostream &, const std::pair<T, U> &);
template <typename... T>
std::ostream &operator<<(std::ostream &, const std::tuple<T...> &);
template <typename T, std::size_t N>
std::ostream &operator<<(std::ostream &, const std::array<T, N> &);

template <typename Tuple, std::size_t N>
struct __TuplePrinter__ {
    static void print(std::ostream &os, const Tuple &t) {
        __TuplePrinter__<Tuple, N - 1>::print(os, t);
        os << ", " << std::get<N - 1>(t);
    }
};

template <typename Tuple>
struct __TuplePrinter__<Tuple, 1> {
    static void print(std::ostream &os, const Tuple &t) { os << std::get<0>(t); }
};

template <typename... T>
std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &t) {
    os << '(';
    __TuplePrinter__<decltype(t), sizeof...(T)>::print(os, t);
    os << ')';
    return os;
}

template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &v) {
    return os << '(' << v.first << ", " << v.second << ')';
}

#define __INNER__                             \
    os << '[';                                \
    for (auto it = begin(c); it != end(c);) { \
        os << *it;                            \
        os << (++it != end(c) ? ", " : "");   \
    }                                         \
    return os << ']';

template <typename T, std::size_t N>
std::ostream &operator<<(std::ostream &os, const std::array<T, N> &c) {
    __INNER__
}

#define __DEFINE__(C)                                           \
    template <typename T>                                       \
    std::ostream &operator<<(std::ostream &os, const C<T> &c) { \
        __INNER__                                               \
    }

#define __DEFINEM__(C)                                             \
    template <typename T, typename U>                              \
    std::ostream &operator<<(std::ostream &os, const C<T, U> &c) { \
        __INNER__                                                  \
    }

#define __DEFINEW__(C, M1, M2)                                  \
    template <typename T>                                       \
    std::ostream &operator<<(std::ostream &os, const C<T> &c) { \
        std::deque<T> v;                                        \
        for (auto d = c; !d.empty(); d.pop()) v.M1(d.M2());     \
        return os << v;                                         \
    }

__DEFINE__(std::vector)
__DEFINE__(std::deque)
__DEFINE__(std::set)
__DEFINEW__(std::stack, push_front, top)
__DEFINEW__(std::queue, push_back, front)
__DEFINEW__(std::priority_queue, push_front, top)
__DEFINE__(std::unordered_set)
__DEFINEM__(std::map)
__DEFINEM__(std::unordered_map)
}

//#define int long long
int ans=0;
int k,n;
vector<int> v(100010);
vector<vector<int>> g(100010);
bool done[100010],doneh[100010];
int dp[100010];



void solve(int now){
	int va=dp[now];
	if(va==-1)va=0;
	int next=v[now];
	if(va==k-1&&next!=0){
		ans++;
		va=-1;
	}
	dp[next]=max(dp[next],va+1);
}

signed main(){
	cin>>n;
	cin>>k;
	lp(i,n){
		cin>>v[i];
		v[i]--;
		if(i!=0)g[v[i]].push_back(i);
		dp[i]=-1;
	}
	if(v[0]!=0)ans++;
	queue<pair<int,int>> q;
	q.push({0,0});
	vector<pair<int,int>> lis;
	while(!q.empty()){
		int now=q.front().first;
		int cnt=q.front().second;
		q.pop();
		if(doneh[now]==1)continue;
		doneh[now]=1;
		lis.push_back({cnt,now});
		if(g[now].empty())continue;
		lp(i,g[now].size()){
			q.push({g[now][i],cnt+1});
		}
	}
	sort(all(lis));
	reverse(all(lis));
	lp(i,lis.size()){
		int now=lis[i].second;
		//cout<<now<<endl;
		if(now==0)continue;
		solve(now);
	}
	cout<<ans<<endl;
	return 0;
}