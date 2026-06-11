#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int N,M;
    cin>>N>>M;
    vector<int>A(N);
    vector<int>B(N);
    for(int i=0; i<N; i++){
        cin>>A.at(i);
        cin>>B.at(i);
    }
    vector<int>C(M);
    vector<int>D(M);
    for(int i=0; i<M; i++){
        cin>>C.at(i);
        cin>>D.at(i);
    }
    for(int i=0; i<N; i++){
        int answer=0;
             int h=1000000000;
        for(int j=0; j<M; j++){
             if(abs(A.at(i)-C.at(j))+abs(B.at(i)-D.at(j))<h){
                 answer=j+1;
               h=abs(A.at(i)-C.at(j))+abs(B.at(i)-D.at(j));
             }
        }
        cout<<answer<<endl;
    }
}
