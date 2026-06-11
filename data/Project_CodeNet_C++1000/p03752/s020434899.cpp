#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main() {
    int N, K;
    cin>>N>>K;
    long a[N];
    for(int i=0;i<N;++i){
        cin>>a[i];
    }

    map<int, int> S;
    long ans = 1e12;
    long tmpans;
    for(int bit=0;bit<(1<<N);++bit){
        tmpans = 0;
        for(int i=0;i<N;++i){
            S[i]=0;
        }
        int num = 0;
        for(int i=0;i<N;++i){
            if(bit&(1<<i)){
                num++;
                S[i]=1;
            }
        }
        if(num!=K)continue;
        if(S[0]==0)continue;
        long height = a[0];
        for(int i=1;i<N;++i){
            if(S[i]==1){
                if(height>=a[i]){
                    tmpans += height - a[i] + 1;
                    height++;
                }
                else height = a[i];
            }
            else{
                if(height<a[i])height = a[i];
            }
        }
        if(tmpans<ans)ans = tmpans;
    }
    cout<<ans<<endl;
}
