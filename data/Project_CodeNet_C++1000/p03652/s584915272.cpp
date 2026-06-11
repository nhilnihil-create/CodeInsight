#include <bits/stdc++.h>

using namespace std;

#define _for(i,j,N) for(int i = (j);i < (N);i++)
#define _rep(i,j,N) for(int i = (j);i <= (N);i++)
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define mk make_pair

typedef long long LL;
typedef pair<int,int> Interval;

template<typename T>
ostream& operator<<(ostream& os,const vector<T>& v) {
    _for(i,0,v.size()) os << v[i] << " ";
    return os;
}

template<typename T>
ostream& operator<<(ostream& os,const set<T>& v){
    for(typename set<T>::iterator it = v.begin();it != v.end();it++)
    os << *it <<" ";
    return os;
}
const int maxn = 305;
int A[maxn][maxn];
int p[maxn];
int N,M;

int main()
{
    scanf("%d %d",&N,&M);
    _for(i,0,N){
        _for(j,0,M){
            scanf("%d",&A[i][j]);
        }
    }
    set<int> dele;
    int ans = N;

    _for(i,0,M-1){
        int maxc = 0;
        int maxm = -1;
        map<int,int> mp;

        _for(i,0,N){
            int &ind = p[i];
            while(dele.count(A[i][ind])){
                ind++;
            }
            if(++mp[A[i][ind]] > maxc){
                maxm = A[i][ind];
                maxc = mp[A[i][ind]];
            }
        }

        ans = min(ans,maxc);
        dele.insert(maxm);
    }

    cout << ans << endl;

    return 0;
}