#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N;
    cin>>N;
    int even[] = {1,2,4,8,16,32,64};
    int ans = 0;
    for(auto i: even){
        if(i<=N)    ans = i;
    }
    cout<<ans<<endl;
    return 0;
}
