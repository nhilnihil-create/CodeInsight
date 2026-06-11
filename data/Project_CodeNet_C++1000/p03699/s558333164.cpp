#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;cin>>N;
    vector<int>S(N);
    int count=0;
    for(int i=0;i<N;i++){
        cin>>S[i];
        count+=S[i];
    }
    if(count%10!=0){
        cout<<count<<endl;
        return 0;
    }
    sort(S.begin(),S.end());
    for(int i=0;i<N;i++){
        int tmp=count-S[i];
        if(tmp%10!=0){
            cout<<tmp<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}
