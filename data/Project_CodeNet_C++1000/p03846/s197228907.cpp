#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
typedef vector<int>         vi;
const int mod = 1000000007;
int modularExponentiation(int x,int n,int M)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modularExponentiation((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    //int arr[n];
    map<int,int> m;
    for(int i =0;i < n;i++){
        int no;
        cin>>no;
        m[no]++;
    }
    if(n%2==0){
        for(int i =1;i <n;i=i+2){
            auto it = m.find(i);
            if(it==m.end()){
                cout<<0<<endl;
                return 0;
            }
            else{
                if(it->second !=2){
                    cout<<0<<endl;
                    return 0;
                }
            }
        }
        cout<<modularExponentiation(2,n/2,mod)<<endl;



    }
    else{
        for(int i =0; i <n;i=i+2){
            auto it = m.find(i);
            if(it==m.end()){
                cout<<0<<endl;
                return 0;
            }
            else{
                if(i==0){
                    if(it->second !=1){
                    cout<<0<<endl;
                    return 0;
                    }
                }
                else{
                    if(it->second !=2){
                    cout<<0<<endl;
                    return 0;
                    }

                }


            }

        }
        cout<<modularExponentiation(2,n/2,mod)<<endl;

    }












}





