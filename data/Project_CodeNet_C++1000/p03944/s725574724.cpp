#include <bits/stdc++.h>
#define FOR(i,n,m) for(int i=n;i<=m;i++)
using namespace std;
int main() {
    int ledo[2]={0,0},riup[2],n;
    cin>>riup[0]>>riup[1]>>n;
    FOR(i,1,n){
        int num[4];
        cin>>num[1]>>num[2]>>num[3];
        switch (num[3]) {
            case 1:if(num[1]>ledo[0])ledo[0]=num[1];
                break;
            case 2:if(num[1]<riup[0])riup[0]=num[1];
                break;
            case 3:if(num[2]>ledo[1])ledo[1]=num[2];
                break;
            case 4:if(num[2]<riup[1])riup[1]=num[2];
                break;
        }
    }

    if(riup[0]<=ledo[0]||riup[1]<=ledo[1])cout<<"0"<<endl;
    else cout<<(riup[1]-ledo[1])*(riup[0]-ledo[0])<<endl;

    return 0;
}
