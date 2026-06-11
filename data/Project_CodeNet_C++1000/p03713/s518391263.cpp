      #include <iostream>
      #include <string>
      #include <vector>
      #include <algorithm>
      #include <map>
      using namespace std;
      typedef long long ll;
      #define rep(i,n) for (int i=0;i < (int)(n);i++)

      int main(){
        int h,w;
        cin >> h >> w;
        ll ans=1LL << 60;
        for (int i=1;i < w;i++){
           ll s1,s2,s3;
           s1 = (ll)h*i;
           if (h%2 == 0){
             s2 = (h/2)*(ll)(w-i);
             s3 = s2;
           }
           else {
             s2 = (h/2)*ll(w-i);
             s3 = ((h+2-1)/2)*ll(w-i);
           }
           ans=min(ans,max({s1,s2,s3})-min({s1,s2,s3}));
           //printf("s1,s2,s3 = (%lld ,%lld %lld) diff %lld\n",s1,s2,s3,max({s1,s2,s3})-min({s1,s2,s3}));
           if ((w-i)%2 == 0 ){
             s2 = (ll)h*(w-i)/2;
             s3 = s2;
           }
           else if ((w-i) != 1){ 
             //printf("w-i/2 %d\n w-i+2-1/2 %d\n",(w-i)/2,(w-i+2-1)/2);
             s2 = ll(h)*((w-i)/2);
             s3 = ll(h)*((w-i+2-1)/2);
           }
           ans=min(ans,max({s1,s2,s3})-min({s1,s2,s3}));
           //printf("s1,s2,s3 = (%lld ,%lld %lld) diff %lld\n",s1,s2,s3,max({s1,s2,s3})-min({s1,s2,s3}));
        }
        for (int i=1;i < h;i++){
           ll s1,s2,s3;
           s1 = (ll)w*i;
           if (w%2== 0){
             s2 = (w/2)*(ll)(h-i);
             s3 = s2;
           }
           else {
             s2 = (w/2)*ll(h-i);
             s3 = ((w+2-1)/2)*ll(h-i);
           }
           ans=min(ans,max({s1,s2,s3})-min({s1,s2,s3}));
           //printf("s1,s2,s3 = (%lld ,%lld %lld)\n diff %lld\n",s1,s2,s3,max({s1,s2,s3})-min({s1,s2,s3}));
           if ((h-i)%2 == 0 ){
             //printf("h-i %d\n",h-i);
             s2 = (ll)w*((h-i)/2);
             s3 = s2;
           }
           else if ((h-i) != 1 ){ 
             s2 = ll(w)*((h-i)/2);
             s3 = ll(w)*((h-i+2-1)/2);
           }
           ans=min(ans,max({s1,s2,s3})-min({s1,s2,s3}));
           //printf("s1,s2,s3 = (%lld ,%lld %lld)\n diff %lld\n",s1,s2,s3,max({s1,s2,s3})-min({s1,s2,s3}));
        }
        cout << ans << endl;
      }
        
        