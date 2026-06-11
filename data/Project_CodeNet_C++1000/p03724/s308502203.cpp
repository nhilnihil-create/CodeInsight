#include<iostream>
#include<map>
using namespace std;

int main() {
    int N, M;
    cin>>N>>M;
    map<int, int>dot;
    int a,b;
    for(int i=0;i<M;++i){
        cin>>a>>b;
        dot[a]++;
        dot[b]++;
    }
    int ans = true;
    for(int i=0;i<N;++i){
        if(dot[i+1]%2 == 1)ans=false;
    }
    if(ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
