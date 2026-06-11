#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using M = map<string,ll>;





int main(){
    ll N;
    cin >> N;
    vector<ll> A(N+1,0);
    for(int i=0;i<N;i++){
        cin>>A[i]
    ;}
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    ll counter1=0; ll counter2=0;
    ll B=0,C=0;
    int i=0;

    while(i<N-1){
        if(counter1==0&&A[i]==A[i+1]){counter1++;C=A[i];i++;}
        else if(counter1==1&&A[i]==A[i+1]){counter2++;B=A[i];break;}
        i++
    ;}
    cout<<B*C<<endl;


return 0;


}  

