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

const int maxn = 1e5+5;
vector<int> G[maxn];
int N;

int solve(int u){
    if(G[u].size() == 0){
        return 0;
    }
    vector<int> vi;
    for(auto v:G[u]){
        vi.push_back(solve(v));
    }
    sort(ALL(vi),greater<int>());
    //cout << vi << endl;
    _for(i,0,vi.size()){
        vi[i] += (i+1);
    }
    return *max_element(ALL(vi));

}

int main()
{
    cin >> N;
    _rep(i,2,N){
        int num;
        scanf("%d",&num);
        G[num].pb(i);
    }

    cout << solve(1) << endl;

    return 0;
}
