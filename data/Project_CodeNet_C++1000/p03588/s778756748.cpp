#include <bits/stdc++.h>
using namespace std;
struct point{double x;double y;};
int i,j,k,count1=0,count2=0;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> vec(n);
    for(i=0;i<n;i++){
        cin>>vec[i].first>>vec[i].second;
    }
    sort(vec.rbegin(),vec.rend());
    cout<<vec[0].first+vec[0].second<<endl;
}