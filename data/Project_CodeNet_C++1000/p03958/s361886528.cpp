#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int K, T;
    cin>>K>>T;
    vector<int> a;
    int tmp;
    for(int i=0;i<T;++i){
        cin>>tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    long nokori = 0;
    for(int i=0;i<T-1;++i){
        nokori += a[i];
    }
    if(a[a.size()-1] - nokori - 1 < 0){
        cout<<0<<endl;
    }
    else {
        cout<<a[a.size()-1] - nokori-1<<endl;
    }
}
