#include <bits/stdc++.h>
using namespace std;
struct point{double x;double y;};
int i,j,k,count1=0,count2=0;

int main(void){
    int n;
    cin>>n;
    vector<int> vec(3*n);
    for(i=0;i<3*n;i++){
        cin>>vec[i];
        cerr<<vec[i]<<" ";
    }
    sort(vec.rbegin(),vec.rend());
    cerr<<endl;
    for(i=0;i<3*n;i++){
        cerr<<vec[i]<<" ";
    }
    cerr<<endl;
    long long int ans=0;
    for(i=1;i<2*n;i++){
        ans+=vec[i];
        i++;
    }
    cout<<ans<<endl;
}