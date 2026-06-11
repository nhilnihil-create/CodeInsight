#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main(){
    int N; cin >> N;
    vector<int> s(N);
    int S = 0;
    for(int i=0;i<N;i++) {cin >> s[i]; S+=s[i];}
    sort(s.begin(), s.end());
    if(S%10==0){
        for(int i=0;i<N;i++){
            if(s[i]%10 != 0) {S-=s[i]; break;}
            if(i == N-1) S = 0;
        }
    }
    cout << S << endl;
}
