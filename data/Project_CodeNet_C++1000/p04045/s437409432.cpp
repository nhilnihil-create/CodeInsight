#include<bits/stdc++.h>
using namespace std;
int a[11];
bool isvalid(int x){
    while(x>0){
    int dig=x%10;
    if(a[dig])
        return false;
    x/=10;
  }
  return true;
}
int main()
{
    //freopen("i.txt","r",stdin);
    int b,n,k;
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>b;
        a[b]++;
    }
    int j=n,f=0;
    while(1){
        if(isvalid(j)){
            break;
        }
        j++;
    }
    cout<<j<<endl;
    return 0;
}
