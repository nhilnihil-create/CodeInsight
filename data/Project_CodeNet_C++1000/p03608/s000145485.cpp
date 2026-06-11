/*#include"bits/stdc++.h"
using namespace std;
using ll=long long;
template<class T=ll>inline T in(istream&is=cin){T ret;is>>ret;return ret;}
template<class T>inline auto vec2(class vector<T>::size_type h,class vector<T>::size_type w,T v=T()){return vector<vector<T>>(h,vector<T>(w,v));}
template<class RandomAccessIterator>inline void psortb(RandomAccessIterator first,RandomAccessIterator last){using P=pair<decltype(first->first),decltype(first->second)>;sort(first,last,[](const P&p1,const P&p2){return p1.second<p2.second||(p1.second==p2.second&&p1.first<p2.first);});}

int main()
{
}*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    const long long INF = 100000000;
    long long N, M, R;
    cin >> N >> M >> R;
    vector<long long>r(R);
    for(long long i = 0; i < R; ++i){
        cin >> r[i];
        // 0-index -> 1-index
        --r[i];
    }
    vector<vector<long long>>adj(N, vector<long long>(N, INF));
    for(long long i = 0; i < M; ++i){
        long long A, B, C;
        cin >> A >> B >> C;
        // 0-index -> 1-index
        --A;--B;
        // 無向グラフ
        adj[A][B] = adj[B][A] = C;
    }

    for(int k=0;k<N;++k){
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                if(adj[i][k]!=INF&&adj[k][j]!=INF){
                    adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
    }
    long long ans=100000000;
    sort(r.begin(),r.end());
    do{
        long long tmp=0;
        for(int i=1;i<R;++i)tmp+=adj[r[i-1]][r[i]];
        ans=min(ans,tmp);
    }while(next_permutation(r.begin(),r.end()));
    cout<<ans<<endl;
}
