#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    map <long long,long long,greater<long long>> dic;
    cin>>N;
    
    for(int i=0; i<N; i++){
        long long a;
        cin>>a;
        dic[a]++;
    }

    long long ans = 1;
    int cnt = 0;

    for(auto a : dic){
        if(cnt == 2) break;
        if(a.second >= 4 && cnt == 0){
            ans = a.first*a.first;
            cnt = 2;
            break;
        }

        if(a.second >= 2){
            ans *= a.first;
            cnt++;
        }
    }

    if(cnt == 2) cout<<ans<<endl;
    else cout<<"0"<<endl;
}