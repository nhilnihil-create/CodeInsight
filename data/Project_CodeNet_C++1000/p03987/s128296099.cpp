#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <iomanip>
#include <set>
using namespace std;

#define rep(i, s) for (int i = 0; i < s; ++i)
#define all(v) (v.begin(), v.end())
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define VEC(a, n) vector<int>a(n)
#define PQ(a) priority_queue<int>a
#define PQmin(a) priority_queue< int, :vector<int>, greater<int> >a
#define PAIR pair<int, int>
/*
sort(sp.begin(), sp.end(), [](PAIR l, PAIR r){
        return l.first<r.first || (l.first==r.first && l.second > r.second);
        });
*/

typedef long long  ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

//数字を入れて場所を出力するようなvectorを作る。
//
int main() {
    ll n;
    cin>>n;
    vector<ll>a(n+1);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.at(x)=i;//数字を入れたら何番目の値かわかるvectorを定義する。
    }
    set<ll>st;
    st.insert(-1);
    st.insert(n);
    ll ans=0;
    // cout<<"a.at(1) = "<<a.at(1)<<endl;
    // cout<<"*st.begin() = "<<*st.begin()<<endl;
    // auto itr = st.end();
    // itr--;
    // cout<<"*st.end() = "<<*itr<<endl;
    for(int i=0;i<n;i++){
        st.insert(a.at(i+1)); //i=0の時、1のindexがなんなのかがわかる。
        auto itr = st.find(a.at(i+1));
        auto itr1 = itr;
        auto itr2 = itr;
        itr1--;
        itr2++;
        ans+=(*(itr) - *(itr1))*(*(itr2) - *(itr)) * (i+1);
        // cout<<"AAA"<<*(itr)<<endl;
    }
    cout<<ans<<endl;



    return 0;
}

