#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair <int, int> P;
#define rep( i, n, m ) for(int i = ( n ); i < ( m ); i++)
#define rep_d( i, n, m ) for(int i = ( n ) - 1; i >= ( m ); i--)
#define sort_asc( X ) sort(( X ).begin(), ( X ).end())
#define sort_desc( X ) sort(( X ).begin(), ( X ).end(), greater <>())

template <class T> bool chmax( T& a, T b );
template <class T> bool chmin( T& a, T b );
int* eratosthenes( int N );
bool bit_search( int pattern, int N );
template <class T> void cumulative_sum( T array, size_t N );

const ll INF = 1LL << 60;
const int k_mod = 1e9 + 7;

int main( void ){
	int N;
	cin >> N;
	vector <string> str( 2 );
	cin >> str[ 0 ];
	cin >> str[ 1 ];
	vector <int> vec;
	int index = 0;
	while(true){
		if(index >= N)
			break;
		if (str[ 0 ][ index ] == str[ 1 ][ index ]){
			vec.push_back( 0 );
			index++;
		}
		else {
			vec.push_back( 1 );
			index += 2;
		}
	}
	int status = vec[ 0 ];
	ll ans = 3;
	if (status == 1)
		ans*=2;
	rep( i, 1, vec.size()){
		if (status == 1){
			if (vec[ i ] == 1)
				ans *= 3;
		}
		else{
			ans *= 2;
		}
		status = vec[i];
		ans %= k_mod;
	}
	cout << ans << endl;
}

int* eratosthenes( int N ){
	int* prime_array = new int[ N + 1 ];
	int lim = N;
	prime_array[ 0 ] = 0;
	prime_array[ 1 ] = 0;
	rep( i, 2, N + 1 ){
		prime_array[ i ] = 1;
	}
	rep( i, 2, lim ){
		if (prime_array[ i ] == 0)
			continue;
		lim = N / i;
		for(int j = i * 2; j < N + 1; j += i){
			prime_array[ j ] = 0;
		}
	}
	return prime_array;
}
template <class T> void cumulative_sum( T array, size_t N ) {
	rep( i, 1, N + 1 ){
		array[ i ] += array[ i - 1 ];
	}
}
template <class T> bool chmax( T& a, T b ) {
	if (a < b){
		a = b; return true;
	}
	return false;
}
template <class T> bool chmin( T& a, T b ) {
	if (a > b){
		a = b; return true;
	}
	return false;
}
bool bit_search( int pattern, int N ){
	int cnt = 0;
	rep( bit, 0, N ){
		if (pattern & ( 1 << bit )){
			cnt++;
		}
	}
	return true;
}
