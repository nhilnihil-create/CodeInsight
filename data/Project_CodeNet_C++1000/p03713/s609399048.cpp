#include "bits/stdc++.h"

typedef long long ll;
using namespace std;

ll mod=1e9+7;

void io(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    

}


int calculate(int h,int w){
    int first_cut = w/3 + w%3 - 1;
    vector<int> v;
    v.push_back(first_cut*h);
    v.push_back((h/2)*(w-first_cut));
    v.push_back(h*w - v[0] - v[1]);
    sort(v.begin(),v.end());
    return v[2]-v[0];
}
int main()
{
    io();
    int h,w,t=1;
    //cin>>t;
    while(t--){
        cin>>h>>w;
        if(h%3 == 0 || w%3 == 0){
            cout<<"0\n";
            continue;
        }
        
        int x=min({calculate(h,w),calculate(w,h),h,w});
        cout<<x<<endl;
    }


}



