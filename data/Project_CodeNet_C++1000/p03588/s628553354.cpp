#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<int>A(N);
    vector<int>B(N);
    for(int i=0;i<N;i++){
        cin>>A.at(i)>>B.at(i);}
    int maxa=0;int ans=0;
    for(int i=0;i<N;i++){
       if(maxa<A.at(i)){maxa=A.at(i);ans=maxa+B.at(i);}
    }
    cout<<ans<<endl;
    return 0;
}