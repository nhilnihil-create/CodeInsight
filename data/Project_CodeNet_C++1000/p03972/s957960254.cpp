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
const LL INF = 1e18;
int W,H;

LL cw[maxn];
LL ch[maxn];

int main()
{
    cin >> W >> H;
    _for(i,0,W){
        cin >> cw[i];
    }
    cw[W] = INF;
    sort(cw,cw+W);
    _for(i,0,H){
        cin >> ch[i];
    }
    ch[H] = INF;
    sort(ch,ch+H);

    int pi = 0;
    int pj = 0;
    int restj = H;
    int resti = W;

    LL need = (W+1)*(LL)(H+1) - 1;

    LL res = 0;
    while(need){
        LL itake = (pi == W)?INF:(restj+1) * cw[pi];
        LL jtake = (pj == H)?INF:(resti+1) * ch[pj];
        if(cw[pi] < ch[pj]){
            res += itake;
            need -= restj + 1;
            pi++;
            resti--;
        }
        else{
            res += jtake;
            need -= resti + 1;
            pj++;
            restj--;
        }
        //cout << "need:"<<need<<" "<<"res:"<<res<< endl;
    }
    cout << res << endl;
    return 0;
}
