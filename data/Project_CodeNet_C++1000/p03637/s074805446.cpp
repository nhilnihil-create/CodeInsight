#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
typedef vector<int>         vi;
const int mod = 1000000007;






int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,odd=0,even=0,div4=0;
    cin>>n;
    for(int i =0;i<n;i++){
        int no;
        cin>>no;

        if(no%2!=0){
            odd++;
        }
        else if (no%4==0){
            div4++;
        }
        else{
            even++;
        }
    }
    if(odd-div4==1 && even==0){
        cout<<"Yes"<<endl;
        return 0;
    }
    else if(div4>=odd){
        cout<<"Yes"<<endl;
        return 0;
    }
    else{
        cout<<"No"<<endl;
        return 0 ;
    }













    }













































