#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main(){
    ll N = 0;
    cin >> N;
    vector<ll> A(N,0);
    for(ll i = 0; i < N; i++) {
    cin >> A.at(i);
    }
    ll ans = 0;
    ll ansa;
    vector<ll> sum(N,0);
    vector<ll> suma(N,0);
    if (A.at(0))
    {sum.at(0) = A.at(0);
    ansa= abs(A.at(0)+(abs(A.at(0))/A.at(0)));
    suma.at(0) = -1*(abs(A.at(0))/A.at(0));
    }
    else
    {
        ans = 1;
        ansa = 1;
        sum.at(0) = 1;
        suma.at(0) = -1;
    }
    
    for (size_t i = 1; i < N; i++)
    {
        sum.at(i) = sum.at(i-1)+A.at(i);
        if (sum.at(i)*sum.at(i-1)<0)
        {
            continue;
        }else
        {
            ans += abs(sum.at(i)+(abs(sum.at(i-1))/sum.at(i-1)));
            sum.at(i)=-1*(abs(sum.at(i-1))/sum.at(i-1));
        }
        
        
    }
    for (size_t i = 1; i < N; i++)
    {
        suma.at(i) = suma.at(i-1)+A.at(i);
        if (suma.at(i)*suma.at(i-1)<0)
        {
            continue;
        }else
        {
            ansa += abs(suma.at(i)+(abs(suma.at(i-1))/suma.at(i-1)));
            suma.at(i)=-1*(abs(suma.at(i-1))/suma.at(i-1));
        }
    }
    //cout << ans << endl;
    cout << min(ans,ansa) << endl;
    /*
    cout << 42123432 << endl;
    cout << sum.at(0) << endl;
    cout << suma.at(0) << endl;
    cout << sum.at(1) << endl;
    cout << suma.at(1) << endl;
*/
    return 0;
}

/*int main() {
    int N = 0;
    cin >> N;
    vector<int> A(N,0);
    for(int i = 0; i < N; i++) {
    cin >> A.at(i);
    }
    int ans = abs(A.at(0)-1);
    int ansa = abs(A.at(0)+1);

    for (size_t i = 1; i < N; i++)
    {
        ans +=abs(A.at(i)-(pow(-1,i)*(2)));
    }
    for (size_t i = 1; i < N; i++)
    {
        ansa +=abs(A.at(i)-(pow(-1,i)*(-2)));
    }
    cout << min(ans,ansa) << endl;
    

    return 0;
}
*/