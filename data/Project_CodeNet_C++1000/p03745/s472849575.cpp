#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main(){
    int N; cin >> N;
    int ans=1;
    int vec=0;
    vector<long long> v(N);
    for(int i=0;i<N;i++){
        cin >>v[i];
        if(i==0) continue;
        if(vec==1){
            if(v[i]<v[i-1]) {vec=0; ans++;}
        }
        else if(vec==0){
            if(v[i]>v[i-1]) vec=1;
            if(v[i]<v[i-1]) vec=-1;
        }
        else if(vec==-1){
            if(v[i]>v[i-1]) {vec=0;ans++;}
        }
    }
    cout << ans << endl;
}
