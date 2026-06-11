#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base:: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int main()
{
    optimize ();
    int a[3],d1,d2,c=0;

    for(int i=0;i<3;i++){
        cin>>a[i];
        if(a[i]==5 || a[i]==7){
            continue;
        }
        else{
        c=1;
        cout<<"NO"<<endl;
        break;
        }
    }
if(c==0){
    sort(a,a+3);
    d1=a[0]-a[1];
    d2=a[2]-a[1];
    if(d1==0 && d2==2 ){
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
    }
    return 0;
}

