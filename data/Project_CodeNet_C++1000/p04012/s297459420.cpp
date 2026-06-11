#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    string a;
    cin>>a;
    int l=a.size();
    int b[1005],k=0,x=0;
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            if(a[i]==a[j])
                x++;
        }
        b[k++]=x;
        x=0;
    }
    for(int i=0;i<k;i++){
        if(b[i]%2==1){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}
