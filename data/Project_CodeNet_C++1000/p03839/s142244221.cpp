#include<bits/stdc++.h>
using namespace std;
#define REP(i,k,n) for(int i=k;i<n;i++)
 
#define INF 1844674407370955161

#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#define MOD 1000000007





int lcm(int a,int b){
	return a/__gcd(a,b) * b;
}

void clear( std::queue<pair<int,int> > &q )
{
   std::queue<pair<int,int> > empty;
   std::swap( q, empty );
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
template<typename T>
std::vector<T> enum_div(T n)//nの約数を列挙
{
	std::vector<T> ret;
	for(T i=1 ; i*i<=n ; ++i)
	{
		if(n%i == 0)
		{
			ret.push_back(i);
			if(i!=1 && i*i!=n)
			{
				ret.push_back(n/i);
			}
		}
	}
	return ret;
}


map< int, int > prime_factor(int n) {
  map< int, int > ret;
  for(int i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}
class DisjointSet{
    public:
        vector<int> rank, p;

        DisjointSet(){
        }

        DisjointSet(int size){
            rank.resize(size, 0);
            p.resize(size, 0);
            for (int i = 0; i < size;i++){
                makeSet(i);
            }
        }
        void makeSet(int x){
            p[x] = x;
            rank[x] = 0;
        }

        bool same(int x,int y){
            return findSet(x) == findSet(y);
        }
        void unite(int x,int y){
            link(findSet(x), findSet(y));
        }
        void link(int x,int y){
            if(rank[x]>rank[y]){
                p[y] = x;
            }else{
                p[x] = y;
                if(rank[x]==rank[y]){
                    rank[y]++;
                }
            }
        }
        int findSet(int x){
            if(x!=p[x]){
                p[x] = findSet(p[x]);
            }
            return p[x];
        }
};



signed main()
{
  int N,K;
  cin>>N>>K;
  long long a[N];
  long long x[N];
  long long b[N];
  REP(i,0,N){
    cin>>a[i];
    x[i]=0;
    b[i]=0;
  }
  x[0]=a[0];
  if(a[0]>0){
    b[0]=a[0];
  }
  REP(i,1,N+1){
    x[i]=x[i-1]+a[i];
    if(a[i]>0){
    b[i]=b[i-1]+a[i];
    }else{
      b[i]=b[i-1];
    }

  }
  if(N==K){
    if(x[N-1]>0){
      cout<<x[N-1]<<endl;
    }else{
      cout<<0<<endl;
    }
    return 0;
  }
  long long ans=0;
  REP(i,0,N-K+1){
    long long tmp=0;

    if(i==0){
      tmp=x[K-1]+b[N-1]-b[K-1];
    }else if(i==N-K){
      tmp=x[N-1]-x[N-K-1]+b[N-K-1];
    }else{
      
      tmp=x[K+i-1]-x[i-1]+b[i-1]+b[N-1]-b[K+i-1];
    }
   
    ans=max(ans,tmp);
    if(i==0){
      tmp=b[N-1]-b[K-1];
    }else if(i==N-K){
      tmp=b[N-K-1];
    }else{
      tmp=b[i-1]+b[N-1]-b[K+i-1];
      
    }
  
    ans=max(ans,tmp);

  }
  cout<<ans<<endl;

}