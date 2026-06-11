#include <iostream>
#include <list>

#define rep(i,n) for(int i=0;i!=(n);++i)

using namespace std;

typedef long long ll; 



int main(){

    int n;
    scanf("%d",&n);

    ll a[n];

    list<ll> list_1;
    list<ll> list_2;
    //vector<ll>::iterator it;

    rep(i,n) cin>>a[i];

    for(int i=0;i<n;++i){

        list_1.push_back(a[i]);

        list_2.push_front(a[i]);
        

        list_1.swap(list_2);


    }

    for(list<ll>::iterator it=list_1.begin();it!=list_1.end();++it){

        cout<<*it<<" ";

    }

    cout<<endl;


}