#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n,m,s,ans,p,q;
ll seg[1<<18];
void add(int a,int b,int r,int l,int k,ll x){
    if(a<=r&&l<=b)seg[k]+=x;
    else if(r<=b&&a<=l){
        add(a,b,r,(r+l-1)/2,k*2+1,x);
        add(a,b,(r+l+1)/2,l,k*2+2,x);
    }
}
void ini(int k,int r,int l){
    if(l-r>0){
        seg[k*2+1]+=seg[k];
        seg[k*2+2]+=seg[k];
        ini(k*2+1,r,(r+l-1)/2);
        ini(k*2+2,(r+l+1)/2,l);
    }
}
int main(void){
    cin>>n>>m>>p;
    p--;
    for(int i=0;i<n-1;i++){
        cin>>q;
        q--;
        if(p<q){
            if(q-p>1){
                add(p+2,q,0,(1<<17)-1,0,-1);
                if(q+1<m)add(q+1,q+1,0,(1<<17)-1,0,q-p-1);
            }
            s+=q-p;
        }else{
            if(!(p==m-1&&q==0)){
                if(p+2<m)add(p+2,m-1,0,(1<<17)-1,0,-1);
                if(0<q)add(1,q,0,(1<<17)-1,0,-1);
                add(q+1,q+1,0,(1<<17)-1,0,m-p+q-1);
            }
            s+=q+1;
        }
        p=q;
    }
    ini(0,0,(1<<17)-1);
    ans=s;
    for(int i=1;i<m;i++){
        s+=seg[i+(1<<17)-1];
        ans=min(ans,s);
    }
    cout<<ans<<endl;
}
