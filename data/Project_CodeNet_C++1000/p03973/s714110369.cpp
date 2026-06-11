#include <bits/stdc++.h>

using namespace std;

#define _for(i,j,N) for(int i = (j);i < (N);i++)
#define _rep(i,j,N) for(int i = (j);i <= (N);i++)
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define mk make_pair

typedef long long LL;
typedef pair<int,int> pi;

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

template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& v){
    os << v.first <<" "<<v.second<<endl;
    return os;
}

const int maxn = 1e5+5;
int A[maxn];
int N;

int main()
{
    LL ans = 0;
    cin >> N;
    _for(i,0,N){
        cin >> A[i];
    }
    ans = (A[0] - 1);
    int minsub = 2;
    _for(i,1,N){
        int num = A[i];
        if(minsub > num) continue;
        if(minsub == num) minsub++;
        else{
            if(num % minsub){
                ans += num/minsub;
            }
            else{
                ans += 1 + (num-minsub-1)/minsub;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
