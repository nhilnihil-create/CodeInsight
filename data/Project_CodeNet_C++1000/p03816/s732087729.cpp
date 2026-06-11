#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned ll;

map<int,int> mmap;
int main(){

    //freopen("test.in","r",stdin);

    int n,tmp;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>tmp;
        mmap[tmp]++;

    }

    //map<int, int>::iterator iter;

    vector<int> cot;
    for(auto iter = mmap.begin();iter!=mmap.end();iter++){
            //cout<<(iter->first)<<' '<<(iter—>second)<<endl;
        tmp=iter->second;
        if(tmp >=2 ) cot.push_back(tmp);
    }

    int two_ct,ct;

    two_ct=ct=0;
    for(int i=0;i<cot.size();i++){
        while(cot[i]>2){
            cot[i]-=2;
            ct++;
        }
        if(cot[i]==2) two_ct++;
    }

    ct+= two_ct/2 + two_ct%2;

    cout<<n-ct*2<<endl;


    return 0;
}
