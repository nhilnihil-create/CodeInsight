#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >>N;
    vector<int>vec(3*N);
    for(int i=0;i<3*N;i++){
        cin>>vec.at(i);
    }
    long long count=0;
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    for(int i=1;i<2*N+1;i+=2){
        count+=vec.at(i);
    }
    cout <<count<<endl;

}