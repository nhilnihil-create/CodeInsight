#include <bits/stdc++.h>

using namespace std;

vector<int> v(100000);

int tru(long long int n,long long int target, long long int a,long long int b){
    long long int hits=0;
    for(int i=0; i<n; i++){
        long long int power=v[i]- target*b;
        if(power>0){
            hits+=(power/a)+((power%a)>0);
        }
    }
    //cout<<"########## "<<hits<<" "<<target<<endl;
    if(hits<target)
        return 0;
    else if(hits==target)
        return 1;
    else
        return 2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int n,a,b;
    cin>>n>>a>>b;
    a-=b;
    long long int x;
    long long int high=0;
    for(int i=0; i<n; i++){
        cin>>x;
        v[i]=x;
        high=max(x,high);
    }
    long long int low=0;
    long long int ans=0;
    long long int mid;
    while(low<=high){
        mid=(low+high)/2;
        int check=tru(n,mid,a,b);
        if(check<=1){
            //cout<<ans<<" !!!!!!!!!!! "<<low<<" "<<high<<" "<<mid<<endl;
            high=mid-1;
        }
        else{
            //cout<<ans<<" @@@@@@@@@@@@ "<<low<<" "<<high<<" "<<mid<<endl;
            //ans=mid;
            low=mid+1;
        }
        if(check==0 || check==1)
            ans=mid;
    }
    cout<<ans<<endl;

    return 0;
}