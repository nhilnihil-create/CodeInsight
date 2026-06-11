    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    #define For(i,n,k) for(ll i=(n);i<(k);i++)
    #define ALL(a)  (a).begin(),(a).end()
    ll ans=0;
    ll n,sq=50,x;
    vector<ll> a(2000);
    vector<ll> badget(50,1e9+7);

    ll find(ll x,ll num){//x番目から左にnum個までのmin
        ll left=x-num+1,right=x;
        ll val=1e9+7;
        if(left==right){
            val=a[left];
        }
        else if(left<0){
            val=min(find(x,x+1),find(n-1,num-x-1));
        }
        else{
            while(left%sq!=0&&left<=right){
                val=min(val,a[left]);
                left++;
            }
            while(right%sq!=0&&left<=right){
                val=min(val,a[right]);
                right--;
            }
            val=min(val,a[right]);
            while(left<right){
                val=min(val,badget[left/sq]);
                left+=sq;
            }
        }
        return val;
    }
    ll calc(ll l){
        ll val=l*x;
        For(i,0,n){
            val+=find(i,l+1);
        }
        return val;
    }
    void Main(){
        cin>>n>>x;
        For(i,0,n){
            cin>>a[i];
            ans+=a[i];
        }

        sq=sqrt(n);
        For(i,0,n){
            badget[i/sq]=min(badget[i/sq],a[i]);
        }

        ll left=0,right=n;
        while(left<right-2){
            ll l1=(2*left+right)/3,l2=(left+2*right)/3;
            if(calc(l1)<calc(l2)){
                right=l2;
            }
            else{
                left=l1;
            }
        }
        
        ans=min({ans,calc(left),calc((left+right)/2),calc(right)});
        cout<<ans<<endl;
    }
    int main(){
        Main();
        return 0;
    }   