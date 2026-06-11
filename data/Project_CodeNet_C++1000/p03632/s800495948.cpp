#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int,bool> mp1;
    map<int,bool> mp2;

    int ans=0;

    for(int i=0;i<=100;i++){
        mp1[i]=false;
        mp2[i]=false;
    }

    int a,b,c,d;
    cin >> a>>b>>c>>d;

    for(int i=a;i<=b;i++){
        mp1[i] =true;
    }
    for(int i=c;i<=d;i++){
        mp2[i] =true;
    }

    for(int i=0;i<=100;i++){
        if(mp1[i] && mp2[i]){
            ans++;
        }
    }
    if(ans!=0) cout << ans-1 << endl;
    else       cout << 0 << endl;
}