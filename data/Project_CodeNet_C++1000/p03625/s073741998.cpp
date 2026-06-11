#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
typedef vector<int>         vi;
const int mod = 1000000007;






int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    map<int,int> m;
    for(int i =0;i<n;i++){
        int no;
        cin>>no;
        m[no]++;
    }
    int ans = 1;
    int cnt =0;
    for(auto it = m.rbegin();it!=m.rend();it++){

            if(it->second >= 4 && cnt==0){
                cout<< it->first *(it->first)<<endl;
                return 0;
            }
            else if(it->second >=2){
                ans = ans*(it->first);
                cnt++;
                if(cnt==2){
                    cout<<ans<<endl;
                    return 0;
                }

            }
    }
    cout<<0<<endl;



    }













































