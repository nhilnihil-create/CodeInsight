#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;
int main(){
    int n,m;
    int kasuga;
    cin>>n>>m;
    long long min;
    long long minyukkar;
    vector<long long> maiyanx(n);
    vector<long long> maiyany(n);
    vector<long long> yukkarx(m);
    vector<long long> yukkary(m);
    for(int i=0;i<n;i++){
        cin>>maiyanx[i]>>maiyany[i];
    }
    for(int i=0;i<m;i++){
        cin>>yukkarx[i]>>yukkary[i];
    }
    for(int i=0;i<n;i++){
        for(int k=0;k<m;k++){
            kasuga=abs(maiyanx[i]-yukkarx[k])+abs(maiyany[i]-yukkary[k]);
            if(k==0){
                min=kasuga;
                minyukkar=k+1;
            }else if(kasuga<min){
                min=kasuga;
                minyukkar=k+1;
            }
        }
        cout<<minyukkar<<endl;
    }
}