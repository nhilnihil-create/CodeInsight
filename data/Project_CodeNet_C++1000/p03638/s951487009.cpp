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
    int h,w,n;
    cin>>h>>w>>n;
    map <int,int> m;
    int arr[h][w];
    for(int i =0;i <n;i++){
        int no;
        cin>>no;
        m[i+1] = no;
    }
    int j =0;
    auto it = m.begin();
    for(int i = 0;i < h;i++){
        if(i%2==0){
            j=0;
            for(;j <w;j++){
                arr[i][j] = it->first;
                it->second --;
                if(it->second==0){
                    it++;
                }
            }
        }
        else{
            j=w-1;
            for(;j >=0;j--){
                arr[i][j] = it->first;
                it->second --;
                if(it->second==0){
                    it++;
                }
            }
        }


    }
    for(int i =0;i < h;i++){
        for(int j =0;j <w;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }










    }













































