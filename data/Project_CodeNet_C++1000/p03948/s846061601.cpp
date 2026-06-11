#include<bits/stdc++.h>
using namespace std;

vector < int > v;

int main(){
    int a_i, b_i, n, temp, t, mini, maxiD, cont = 0;

    cin>>n>>t;

    v.resize( n );

    for( a_i=0; a_i<n; a_i++ ) cin>>v[a_i];

    mini = v[0]; maxiD = 0;

    for( a_i=0; a_i<n; a_i++ ){
        mini = min( v[a_i], mini );
        maxiD = max( maxiD, v[a_i]-mini );
    }

    mini = v[0];
    for( a_i=0; a_i<n; a_i++ ){
        mini = min( v[a_i], mini );
        if( v[a_i]-mini == maxiD ) cont++;
    }

        cout<<cont<<endl;

}
