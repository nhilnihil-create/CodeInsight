#include <iostream>
#include <map>
#include <utility>
using namespace std;

typedef long long lint;

int root(int *uni,int a){
    if(uni[a]<0) return a;
    else return uni[a]=root(uni, uni[a]);
}
bool connect(int *uni,int ia,int ib){
    int a=root(uni,ia),b=root(uni,ib);
    if(a==b) return false;

    if(uni[a]>uni[b]){
        uni[b]+=uni[a];
        uni[a]=b;
    }else{
        uni[a]+=uni[b];
        uni[b]=a;
    }
    return true;
}

int main(){
    int N,K,L;
    cin >> N >> K >> L;

    int *road,*train;
    road=new int[N+1];
    train=new int[N+1];
    for(int i=0;i<N;i++) road[i]=train[i]=(-1);

    int p,q,r,s;
    for(int i=0;i<K;i++){
        cin >> p >> q;
        connect(road,p-1,q-1);
    }
    for(int i=0;i<L;i++){
        cin >> r >> s;
        connect(train,r-1,s-1);
    }

    map<pair<int,int>,int> roots;

    for(int i=0;i<N;i++) roots[make_pair(root(road,i),root(train,i))]++;

    for(int i=0;i<N;i++){
        cout << roots[make_pair(root(road,i),root(train,i))];

        if(i==N-1) cout << endl;
        else cout << ' ';
    }
    
    delete[] road,train;
    return 0;
}//