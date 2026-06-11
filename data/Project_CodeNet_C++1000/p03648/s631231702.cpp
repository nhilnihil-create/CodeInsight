#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll k,o=50,n;
vector<ll>ans;
int main(void){
    cin>>k;
    cout<<50<<endl;
    o+=k/50;
    n=50-k%50;
    for(int i=0;i<n;i++)ans.push_back(o-k%50-i-1);
    for(int i=n;i<50;i++)ans.push_back(o+n);
    for(int i=0;i<ans.size()-1;i++)cout<<ans[i]<<' ';
    cout<<ans.back()<<endl;
}
