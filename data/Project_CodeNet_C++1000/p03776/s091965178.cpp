#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    long long v[n];
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v,v+n,greater<long long>());
    long long m=0;
    for(int i=0;i<a;i++)m+=v[i];
    cout<<m/a<<".";
    m%=a;
    m*=1000000000;
    cout<<m/a<<endl;
    a--,b--;
    int l=lower_bound(v,v+n,v[a],greater<long long>())-v,r=upper_bound(v,v+n,v[a],greater<long long>())-v;
    int vali=r-l;
    long long c[vali+1];//combination
    //MAX = 50 C 25 < 1.3*10^14
    long long wa[vali+1];
    c[0]=1;
    wa[0]=1;
    for(int i=1;i<=vali;i++){
        c[i]=c[i-1]*(vali-i+1)/i;
        wa[i]=wa[i-1]+c[i];
    }
    if(v[a]<v[0])cout<<c[a-l+1]<<endl;
    else{
        if(v[a]==v[b]){//vali C a～b
            cout<<wa[b-l+1]-wa[a-l]<<endl;
        }
        else{//vali C a～vali
            cout<<wa[vali]-wa[a-l]<<endl;
        }
    }
    return 0;
}
