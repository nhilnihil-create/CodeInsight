#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 * 1000 + 10;

int n;

int arr[MAXN];
bool check_arr[MAXN];

bool check(int x)
{

    //cerr << "x: " << x << endl;

    for(int i = 0; i < 2 * n - 1; i++){
        check_arr[i] = false;
        if(arr[i] < x) check_arr[i] = true;
        //cerr << check_arr[i] << ' ';
    }
    //cerr << endl;
    bool result;
    int nearest = MAXN;

    for(int i = (2 * n - 1) / 2; i < 2 * n - 2; i++){
        if(check_arr[i] == check_arr[i + 1]){
            nearest = i - (2 * n - 1) / 2;
            result = check_arr[i];
            break;
        }
    }

    //cerr << "nearest : " << nearest << ' ' << result << endl;

    for(int i = (2 * n - 1) / 2; i > 0; i--){
        if(check_arr[i] == check_arr[i - 1]){
            if(nearest > (2 * n - 1) / 2 - i){
                nearest = (2 * n - 1) / 2 - i;
                result = check_arr[i];
            }
            break;
        }
    }
     //cerr << "nearest : " << nearest << ' ' << result << endl;
    if(nearest == MAXN){
        if(check_arr[0] == false)
            return 0;
        return 1;
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //cout << fixed << setprecision(10);

    cin >> n;

    for(int i = 0; i < 2 * n - 1; i++) cin >> arr[i];

    int l = 1, r = 2 * n;
    while(r - l > 1){
        int mid = (l + r) / 2;

        if(check(mid)){
            r = mid;
        }
        else{
            l = mid;
        }
        //cerr << "mid : " << mid << " = " << check(mid) << endl;
    }
    cout << l << endl;

    return 0;
}

