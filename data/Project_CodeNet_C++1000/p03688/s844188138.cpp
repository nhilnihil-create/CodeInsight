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
const int maxn = 1e5+5;
int A[maxn];

int main()
{
    int N;
    cin >> N;
    int min_h = maxn;
    int max_h = 0;
    _for(i,0,N){
        cin >> A[i];
        min_h = min(min_h,A[i]);
        max_h = max(max_h,A[i]);
    }

    if(max_h > min_h + 1){
        printf("No\n");
    }
    else if(max_h == min_h + 1){
        int cmin = 0,cmax = 0;
        int ok = 1;
        _for(i,0,N){
            if(A[i] == min_h) cmin++;
            else cmax++;
        }
        if(cmin >= max_h) ok = 0;
        max_h -= cmin;
        if(cmax/2 < max_h) ok = 0;
        if(ok) printf("Yes\n");
        else printf("No\n");
    }
    else{
        if(N == max_h+1){
            printf("Yes\n");
            return 0;
        }
        if(N/2 >= max_h){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }

    }
    return 0;
}