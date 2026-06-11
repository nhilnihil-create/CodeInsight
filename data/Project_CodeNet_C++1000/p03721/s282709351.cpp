#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define In_The_Name_Of_Allah_The_Merciful ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Alhamdulillah return 0;
#define debug(n) cerr << "[" << #n << " = " << n << "]" << endl 

struct Fenwick {

    #define T ll

    vector <T> bit;
    int sz;

    void init (int n){
        sz = (1 << (int)ceil(log2(n+1)));
        bit.resize(sz+1);
    }

    T query (int x){
        T sum = 0;
        for(; x ; x -= x&-x){
            sum += bit[x];
        }
        return sum;
    }

    void update(int x , T val){
        for(; x <= sz ; x += x&-x)
            bit[x] += val;
    }

    T Sum (int st , int en){
        return query(en) - query(st-1);
    }

    void Clear (){
        for (int i = 0 ; i <= sz ; ++i)
            bit[i] = 0;
    }


    int FindIdx (T v){
        int l = 1 , r = sz;
        while (l < r){
            int mid = l + (r-l) / 2;
            if (bit[mid] < v)
                l = mid + 1 , v -= bit[mid];
            else
                r = mid;
        }
        return l;
    }

};

void Suhaib_Sawalha (){

    Fenwick fen;
    int n;
    ll k;
    cin >> n >> k;
    int a , b;
    fen.init(1e5);
    while (n--){
        cin >> a >> b;
        fen.update(a,b);
    }

    int mx = 1e5;
    for (int i = 1 ; i <= mx ; ++i){
        ll r = fen.Sum(i,i);
        if (r >= k){
            cout << i;
            return;
        }
        k -= r;
    }

}

int main(){
                                In_The_Name_Of_Allah_The_Merciful   /* بسم الله الرحمن الرحيم  */
#ifndef ONLINE_JUDGE
    freopen("SuhaibSawalha1.txt","r",stdin);
#endif
//int _;for(cin>>_;_;--_,cout<<'\n')
        Suhaib_Sawalha();
                                         Alhamdulillah                    /* الحمد لله */
}