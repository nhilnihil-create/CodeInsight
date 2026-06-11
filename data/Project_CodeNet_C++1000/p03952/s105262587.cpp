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

template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& v){
    os << v.first <<" "<<v.second<<endl;
    return os;
}

const int maxn = 2e5+5;
int A[maxn],N,x;

int main()
{
    cin >> N >> x;
    if(x == 1 ||  x == 2*N-1){
        printf("No\n");
    }else{
        printf("Yes\n");
        int mid = N;
        int temp = x+1;
        int temp2 = x-1;
        if(x <= N){
            A[mid] = x;
            while(--x){
                A[--mid] = x;
            }
            while(--mid >= 1){
                A[mid] = temp++;
            }
            _rep(i,N+1,2*N-1){
                A[i] = temp++;
            }
        }
        else{
            A[mid] = x;
            while(++x <= 2*N-1){
                A[++mid] = x;
            }
            while(++mid <= 2*N-1){
                A[mid] = temp2--;
            }
            for(int i = 1;i < N;i++){
                A[i] = temp2--;
            }
        }
        _rep(i,1,2*N-1){
            printf("%d\n",A[i]);
        }

    }

    return 0;
}
