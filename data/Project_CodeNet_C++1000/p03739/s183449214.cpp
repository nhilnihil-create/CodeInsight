#include <bits/stdc++.h>
using namespace std;

int n;
int a[100010];
long long sum[100010];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // 偶数項が正
    long long cnt1 = 0;
    sum[0] = a[0];
    while(sum[0]<=0){
        sum[0]++;
        cnt1++;
    }

    for (int i = 1; i < n; i++)
    {
        sum[i] = sum[i-1] + a[i];
        if(i%2 == 0){
            while(sum[i]<=0){
                sum[i]++;
                cnt1++;
            }
        } else {
            while(sum[i]>=0){
                sum[i]--;
                cnt1++;
            }
        }
    }
    



    // 奇数項が正、偶数項が負
    long long cnt2 = 0;
    sum[0] = a[0];
    
    while(sum[0]>=0){
        sum[0]--;
        cnt2++;
    }

    for (int i = 1; i < n; i++)
    {
        sum[i] = sum[i-1] + a[i];
        if(i%2 == 1){
            while(sum[i]<=0){
                sum[i]++;
                cnt2++;
            }
        } else {
            while(sum[i]>=0){
                sum[i]--;
                cnt2++;
            }
        }
    }

    long long cnt = min(cnt1,cnt2);

    cout << cnt << endl;

    return 0;
}
