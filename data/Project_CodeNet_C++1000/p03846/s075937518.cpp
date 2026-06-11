#include <bits/stdc++.h>

using namespace std;

long long mod = 1e9 + 7;

int main() {

    cin.tie(0); ios_base::sync_with_stdio(0); //Don't ever delete this line

    int n;

    cin >> n;

    vector <int> v(n);

    for(int i=0;i<n;i++){

        cin >> v[i];

    }

    sort(v.begin(),v.end());

    if(n%2==0){

        bool notzero=true;

        for(int i=1;i<=n/2;i++){

            if(v[2*(i-1)]!=(2*(i-1)+1)||v[2*(i-1)+1]!=(2*(i-1)+1)){

                notzero=false;

            }

        }

        if(notzero==false){cout<<0<<"\n";}

        else{

            long long ans = 1;

            for (int i = 0; i < n/2; i++) {

                    ans = (ans * 2) % mod;

                }

            cout << ans << "\n";

        }

    }

    else{

        bool notzero=true;

        if(v[0]!=0)notzero=false;

        for(int i=1;i<=n/2;i++){

            if(v[2*(i)]!=(2*i)||v[2*(i)-1]!=(2*i)){

                notzero=false;

            }

        }

        if(notzero==false){cout<<0<<"\n";}

        else{

            long long ans = 1;

            for (int i = 0; i < n/2; i++) {

                    ans = (ans * 2) % mod;

                }

            cout << ans << "\n";

        }

    }

	return 0;

}