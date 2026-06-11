#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll Ten(int x){
ll ret=1;
while( x-- )ret*=10ll;
return ret;
}

int ask(ll n){
cout<<"? "<<n<<endl;
cout.flush();
char c;
cin>>c;
return c=='Y';
}

int main(){

if( ask( Ten(9) ) ){

for(int i=0;i<=10;i++){
    if( ask( 2ll*Ten(i) ) ){
        cout<<"! "<<Ten(i)<<endl;
        return 0;
    }
}

}else{


for(int i=0;i<=15;i++)
if( !ask( Ten(i) ) ){

    ll low = Ten(i-1) , high=Ten(i)-1;
    while( low < high ){
        ll mid = low+high>>1;
        if( ask(10ll*mid) )high=mid;
        else low=mid+1;
    }

    cout<<"! "<<high<<endl;
    return 0;
}

}


return 0;
}
