#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long
#define MAX_N 800001

using namespace std;

long long MOD = 1000000007;

struct segment_tree{
    ll tree[MAX_N];
    int size;

    segment_tree(int N){
        int n=1;
        while(N>n){
            n<<=1;
        }
        size=2*n;
        
        for(int i=0; i<size; i++){
            tree[i]=MOD*MOD;
        }
    }

    void update(int k, ll x){
        k+=(int)(size>>1)-1;
        tree[k]=x;

        while(k>0){
            k=(k-1)/2;
            tree[k]=min(tree[2*k+1],tree[2*k+2]);
        }
    }

    ll query(int a, int b){
        return query(a,b,0,0,(size>>1));
    }

    ll query(int a, int b, int k, int l, int r){
        if(b<=l || r<=a){
            return MOD*MOD;
        }else if(a<=l && r<=b){
            return tree[k];
        }else{
            ll ret=MOD*MOD;
            ret=min(ret,query(a,b,2*k+1,l,(l+r)/2));
            ret=min(ret,query(a,b,2*k+2,(l+r)/2,r));
            return ret;
        }
    }
};

template<typename T>
void cout_vec(vector<T> &vec){
    for(int i=0; i<vec.size(); i++){
        if (i!=0){
            cout << ' ';
        }
        cout << vec[i];
    }
    cout << endl;
}

int N;
vector<int> pos(200001);
ll partition_(ll l, ll r, segment_tree &st){
    if(r-l==1){
        return st.query(l, r);
    }else if(r-l==0){
        return 0;
    }

    ll ret=0;
    ll min_=st.query(l,r);
    ret+=min_*(pos[min_]-l+1)*(r-pos[min_]);
    ret+=partition_(l, pos[min_],st);
    ret+=partition_(pos[min_]+1, r, st);
    return ret;
}

int main(){
    cin >> N;
    segment_tree st(N);
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        st.update(i, a);
        pos[a]=i;
    }

    cout << partition_(0,N,st) << endl;
}