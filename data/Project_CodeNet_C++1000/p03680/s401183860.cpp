/*
        karmany evadhikaras te
        ma phalesu kadacana 
        ma karma-phala-hetur bhur
        ma re sango'stv akarmani (B.G.-2.47)
 
Translation:
        Lord Krsna to Arjuna.
You have a right to perform your prescribed duty, 
but you are not entitled to the fruits of action. 
Never consider yourself the cause of the results of your activities, 
and never be attached to not doing your duty.    
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int long long
const int N = 200005;
const ll mod = 2000000011;
#define ld long double
#define PI 3.14159265358979323846
const int X = 10000000;

void flash()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(20);
}

//3. Structure or classes
//3. Ends here

//1. Data structures declaration here
vector<int>Next;
//1. Ends here

//2. Extra Functions here
//2. Ends here


void solve();
int32_t main()
{
    flash();
    int t;
    t = 1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        solve();
    }
    return 0;
}

void solve()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    bool vis[n+1]={0};
    int start=a[1];
    int cnt=0;
    while(true){
        //cout<<start<<" ";
        cnt++;
        if(vis[start]==0){
            vis[start]=1;
        }
        else break;
        if(start==2)break;
        start=a[start];
    }
    if(vis[2]==1)cout<<cnt<<"\n";
    else cout<<"-1\n";
    return;
}