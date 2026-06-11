#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int N;
    int K;
    int a[60];

    int ans=0;

    cin>>N>>K;
    for(int i=0;i<N;++i){
        cin>>a[i];
    }

    sort(a, a+N,greater<int>());

    for(int i=0;i<K;++i){
        ans+=a[i];
    }

    cout<<ans<<endl;

    return 0;

}