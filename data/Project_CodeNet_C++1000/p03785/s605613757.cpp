#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;

int main(){
    long long N,C,K; cin >> N >> C >> K;
    vector<long long> v(N);
    for(int i=0;i<N;i++)cin>>v[i];
    sort(v.begin(),v.end());
    long long next = v[0]+K;
    int n_bus=0;
    int count=0;
    while(true){
        int n_pas = 0;
        for(int i=0;i<v.size();i++){
            if(v[i]<=next) n_pas++;
            else break;
        }
        if(n_pas>C){
            n_bus += n_pas/C;
            v.erase(v.begin(), v.begin()+n_pas-n_pas%C);
        }else{
            n_bus++;
            v.erase(v.begin(), v.begin()+n_pas);
        }
        if(v.size() == 0) break;

        next = v[0]+K;
    }
    cout << n_bus << endl;
}
