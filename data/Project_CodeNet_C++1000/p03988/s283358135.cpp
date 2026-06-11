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

int cnt[100];

signed main(){
	int n;
	cin>>n;
	int maxi=-1;
	lp(i,n){
		int a;
		cin>>a;
		cnt[a]++;
		maxi=max(maxi,a);
	}
	bool can=true;
	int be=(maxi+1)/2;
	for(int i=maxi;i>=be;i--){
		if(i==be){
			if(maxi%2==1){
				if(cnt[i]>=2){
					cnt[i]-=2;
				}
				else{
					can=false;
				}
			}
			else{
				if(cnt[i]>=1){
					cnt[i]-=1;
				}
				else{
					can=false;
				}

			}
		}
		else{
			if(cnt[i]>=2){
				cnt[i]-=2;
			}
			else{
				can=false;
			}
		}
	}
	if(cnt[be]!=0)can=false;
	lp(i,be){
		if(cnt[i]>=1)can=false;
	}
	if(can){
		cout<<"Possible"<<endl;
	}
	else{
		cout<<"Impossible"<<endl;
	}
	return 0;
}