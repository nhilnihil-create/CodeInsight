#include <bits/stdc++.h>
using namespace std;


int main(){


    long long n, w, i, j, f, l, t, s, x;

    long long k = 0;

    long long m = 0;


 
    cin >> n >> w;


    vector<long long> w0(n);

    vector<long long> w1(n);

    vector<long long> w2(n);

    vector<long long> w3(n);


    cin >> x >> s;

    w0.at(0) = s;


    for( i = 0 ; i < n - 1 ; i = i + 1 ){

         cin >> t >> s;

         if( t - x == 0 ) w0.at(i + 1) = s;

         else if( t - x == 1 ) w1.at(i) = s;

         else if( t - x == 2 ) w2.at(i) = s;

         else if( t - x == 3 ) w3.at(i) = s;

         }


    sort( w0.rbegin(), w0.rend() );

    sort( w1.rbegin(), w1.rend() );

    sort( w2.rbegin(), w2.rend() );

    sort( w3.rbegin(), w3.rend() );



    vector<long long> s0(n + 1);

    vector<long long> s1(n + 1);

    vector<long long> s2(n + 1);

    vector<long long> s3(n + 1);



    for( i = 0 ; i < w0.size() + 1 ; i = i + 1 ){

         if( i == 0 ) s0.at(i) = 0;

         else s0.at(i) = s0.at(i - 1) + w0.at(i - 1);

         }

    for( i = 0 ; i < w1.size() + 1 ; i = i + 1 ){

         if( i == 0 ) s1.at(i) = 0;

         else s1.at(i) = s1.at(i - 1) + w1.at(i - 1);

         }

    for( i = 0 ; i < w2.size() + 1 ; i = i + 1 ){

         if( i == 0 ) s2.at(i) = 0;

         else s2.at(i) = s2.at(i - 1) + w2.at(i - 1);

         }

    for( i = 0 ; i < w3.size() + 1 ; i = i + 1 ){

         if( i == 0 ) s3.at(i) = 0;

         else s3.at(i) = s3.at(i - 1) + w3.at(i - 1);

         }


    for( i = 0 ; i < s0.size() ; i = i + 1 ){ 

         for( j = 0 ; j < s1.size() ; j = j + 1 ){ 

              for( f = 0 ; f < s2.size() ; f = f + 1 ){ 

                   for( l = 0 ; l < s3.size() ; l = l + 1 ){

                        if( x * i + ( x + 1 ) * j + ( x + 2 ) * f + ( x + 3 ) * l <= w ){

                            k += s0.at(i) + s1.at(j) + s2.at(f) + s3.at(l);

                            m = max(k, m);

                            k = 0;

                            }

                        }

                   }

               }

          }


    cout << m << endl;


    return 0;


    }