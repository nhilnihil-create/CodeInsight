#include<iostream>
#include<string>

using namespace std;
typedef long long ll;

ll n;
string s;

ll a[100010]={0};
bool f1,f2;

signed main(){
    cin>>n>>s;

    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            a[0]=i,a[1]=j;
            f1=false,f2=false;
            for(int k=2;k<n;++k){
                if(a[k-1]==1&&s[k-1]=='o'||a[k-1]==0&&s[k-1]=='x')a[k]=a[k-2];
                else a[k]=1-a[k-2];
            }
            if(a[0]==1){
                if((s[0]=='o')==(a[1]==a[n-1])){
                   f1=true;
                }
            }
            if(a[0]!=1){
                if((s[0]=='o')!=(a[1]==a[n-1])){
                    f1=true;
                }
            }

            if(a[n-1]==1){
                if((s[n-1]=='o')==(a[n-2]==a[0])){
                   f2=true;
                }
            }
            if(a[n-1]!=1){
                if((s[n-1]=='o')!=(a[n-2]==a[0])){
                    f2=true;
                }
            }
            if(f1&&f2)i=2,j=2;
        }
    }

    if(!(f1&&f2)){
        cout<<-1<<endl;
        return 0;
    }

    for(int i=0;i<n;++i){
        if(a[i]==1)printf("S");
        else printf("W");
    }
    cout<<endl;

    return 0;
}