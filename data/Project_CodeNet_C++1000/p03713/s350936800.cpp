        #include <bits/stdc++.h>
        using namespace std;
        #define int long long

        signed main() {
        int h,w;
        cin>>h>>w;
        if(h%3==0||w%3==0){
            cout<<0;
            return 0;
        }
        int ans=min(h,w);
       int a[3]={};
        for(int i=1;i<h;i++){
            a[0]=i*w;
            a[1]=(h-i)*(w/2);
            a[2]=(h-i)*(w - w/2);
            sort(a,a+3);
            ans=min(ans,a[2]-a[0]);
        }
         for(int i=1;i<w;i++){
            a[0]=i*h;
            a[1]=(w-i)*(h/2);
            a[2]=(w-i)*(h - h/2);
            sort(a,a+3);
            ans=min(ans,a[2]-a[0]);
        }
        cout<<ans;
        }
