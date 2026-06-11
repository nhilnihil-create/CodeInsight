#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    set<int> dic;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin>>A[i];

    for(int i=0; i<N; i++){
        if(!dic.count(A[i])) dic.insert(A[i]);
    }

    int ans;

    ans = ((int)dic.size()%2==0 ? (int)dic.size()-1 : (int)dic.size());

    cout<<ans<<endl;

    return 0;
}