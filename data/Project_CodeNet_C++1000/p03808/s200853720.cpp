#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll a[100002];
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum % (n * (n + 1) / 2) != 0){
        cout << "NO" << endl;
        return 0;
    }
    ll lar[100002] {0};
    ll sumlar = 0;
    ll t = sum / (n * (n + 1) / 2);
    for(int i = 0; i < n; i++){
        if((a[i] + t - a[(i + 1) % n]) % n != 0){
            cout << "NO" << endl;
            return 0;
        }
        lar[i] = (a[i] + t - a[(i + 1) % n]) / n;
        sumlar += lar[i];
    }
    if((t - sumlar) % n != 0){
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        lar[i] += (t - sumlar) % n;
        if(lar[i] < 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}