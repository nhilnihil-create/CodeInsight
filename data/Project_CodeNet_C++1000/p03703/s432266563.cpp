#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include<random>
#include <bitset>
using namespace std;
#define N (1000000000+7)
//#define N 998244353
#define INF 1e16
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> Q;
 
const int inf = (int)1e9; 
 
ll gcd(ll a, ll b) {
	if (b > a) {
		ll tmp = b;
		b = a;
		a = tmp;
	}
	if (a%b == 0)return b;
	else return gcd(b, a%b);
}

template<typename T>
struct BIT{
    private:
    vector<T> array;
    const int length;
    
    public:

    BIT(int _n) : array(_n+1),length(_n){}

    T sum(int i){
        T s=0;
        while(i>0){
            s+=array[i];
            i -= i&(-i);
        }
        return s;
    }

    T sum(int i,int j){
        T ret1 = sum(i-1);
        T ret2 = sum(j);
        return ret2-ret1;
    }

    void add(int i,T x){
        while(i<=length){
            array[i]+=x;
            i += i&(-i);
        }
    }
};

vector<ll>a,sum;
ll n,k;

vector<int> Compress(vector<ll> &tmp){
    sort(tmp.begin(),tmp.end());
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    vector<int>ans;
    for(int i=0;i<sum.size();i++){
        int id = lower_bound(tmp.begin(),tmp.end(),sum[i])-tmp.begin();
        ans.push_back(id);
    }
    return ans;
}

int main(void){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		a.push_back(x);
	}
	ll s = 0;
	sum.push_back(0);
	for(ll i=0;i<n;i++){
		s+=a[i];
		sum.push_back(s-k*(i+1));
	}
	vector<ll>tmp = sum;
	vector<int>A = Compress(tmp);
	BIT<ll>bit = BIT<ll>((int)A.size());
	ll ans = 0;
	for(int i=0;i<A.size();i++){
		ans+=bit.sum(A[i]+1);
		bit.add(A[i]+1,1);
	}
	cout<<ans<<endl;
	return 0;
}