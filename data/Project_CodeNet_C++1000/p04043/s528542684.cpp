#include<bits/stdc++.h>

using namespace std;
#define Pi acos(-1)
#define _terminated return 0
#define endl "\n"
#define yes cout << "yes" << endl 
#define no cout << "no" << endl 
#define booster ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<long> > v2l;

const int mod = 1e+5;
const int mx = 2e+5;
const ll inf = 1e18;

using namespace std;

void solvio(void){
     int a,b,c;
     cin >> a >> b >> c;
     if((a==5 && b==7 && c==5)||(a==5 && b==5 && c==7)||(a==7 && b==5 && c==5))
     cout << "YES" << endl;
     else cout << "NO" << endl; 
}


int main(){ 
    booster;
    solvio(); 
    _terminated; 
}