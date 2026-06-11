#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

vector<int>res;
int main(int argc, char *argv[]) {
    int n,k,tmp;
    int ans = 1;
    cin>>n>>k;
    for(int i = 0 ; i < n ; ++i){
        cin>>tmp;
        res.push_back(tmp);
    }
    int mins = res[0];
    int maxs = 0;
    for(int i = 1 ; i < n ; ++i){
        if(maxs==res[i]-mins){
            ans++;
        }
        if(maxs<res[i]-mins){
            maxs = res[i]-mins;
            ans = 1;
        }
        mins = min(res[i],mins);
    }
    cout<<ans<<endl;
    return 0;
}
