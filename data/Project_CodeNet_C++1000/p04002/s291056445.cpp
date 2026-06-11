#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int main(void){
    long long h,w,n,d=1000000000,c[10]={0};
    unordered_map<long long,int> m{};
    cin>>h>>w>>n;
    for(int i=0;i<n;i++){
        long long a,b;
        cin>>a>>b;
        a--;
        b--;
        for(int j=-1;j<=1;j++){
            for(int k=-1;k<=1;k++){
                if(a+j>=0&&a+j<h&&b+k>=0&&b+k<w){
                    m[(a+j)*d+b+k]++;
                    //cout<<a+j<<","<<b+k<<":"<<m[(a+j)*d+b+k]<<endl;
                }
            }
        }
        
    }
    for(auto x=m.begin();x!=m.end();x++){
        long long a=(x->first)/d,b=(x->first)%d;
        if(a>=1&&a<=h-2&&b>=1&&b<=w-2){
            c[x->second]++;
            c[0]++;
        }
    }
    cout<<(h-2)*(w-2)-c[0]<<endl;
    for(int i=1;i<=9;i++){
        cout<<c[i]<<endl;
    }
}
