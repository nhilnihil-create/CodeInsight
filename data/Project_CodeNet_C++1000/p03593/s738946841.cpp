#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

int main() {
    int H, W;
    cin>>H>>W;
    vector<string> a;
    string tmp;
    for(int i=0;i<H;++i){
        cin>>tmp;
        a.push_back(tmp);
    }
    map<char, int> amap;
    vector<char> aarr;
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j){
            if(amap[a[i][j]]==0){
                aarr.push_back(a[i][j]);
            }
            amap[a[i][j]]++;
        }
    }

    int two=0, one=0;
    if(H%2==1){
        two += W;
    }
    if(W%2==1){
        two += H;
    }
    if((H%2==1) & (W%2==1)){
        one++;
        two--;
    }
    int onenum=0, twonum=0;
    for(int i=0;i<aarr.size();++i){
        if(amap[aarr[i]]%4==2) twonum+=2;
        else if(amap[aarr[i]]%4==1) onenum++;
        else if(amap[aarr[i]]%4==3){
            onenum++;
            twonum+=2;
        }
    }
    if(one!=onenum | two<twonum){
        cout<<"No"<<endl;
    }
    else cout<<"Yes"<<endl;
}
