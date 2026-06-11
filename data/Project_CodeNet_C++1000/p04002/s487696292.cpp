#include <bits/stdc++.h>
using namespace std;

long long h,w,n,u,v,s,t,cs=0,kq[15],dem,p,q;
struct st{
    long long x,y;
};
st a[1000010];

bool cmp(st c, st d){
    if (c.x==d.x) return c.y < d.y;
    else return c.x < d.x;
}

int main()
{
    cin >> h >> w >> n;
    for (long i=1;i<=n;i++){
        cin >> u >> v;
        for (int j=0;j<=2;j++){
        for (int k=0;k<=2;k++){
            s=u-j;
            t=v-k;
            if (s>0 && t>0 && s<=h-2 && t<=w-2){
                cs++;
                a[cs].x=s;
                a[cs].y=t;

            }

        }
        }
    }
    //cout << p << " " << q << endl;
    p=(h-2)*(w-2);
    sort(a+1,a+1+cs,cmp);
    dem=1;
  //  for (long i=1;i<=cs;i++) cout << a[i].x << " " << a[i].y << endl;
    for (long i=2;i<=cs+1;i++){
        if (a[i].x==a[i-1].x && a[i].y==a[i-1].y) dem++;
        else {
            kq[dem]++;
            dem=1;
            q++;
        }
    }
    kq[0]=p-q;
    for (int i=0;i<=9;i++) cout << kq[i] << endl;
    return 0;
}
