#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 50;

string Ret;

bool Ask( string x ){
	cout << "? " << x << endl;
	flush( cout );
	string ans;
	cin >> ans;
	if( ans == "Y" )
		return true;
	return false;
}

int PreDeal(){
	int l = 1 , r = 10;
	while( l < r ){
		int mid = l + r + 1 >> 1;
		string tr;
		tr.push_back( '1' );
		for(int i = 1 ; i < mid ; ++ i) tr.push_back( '0' );
		if( Ask( tr ) )
			l = mid ;
		else
			r = mid - 1;
	}
	return l;
}

int main( int argc , char * argv[] ){
	int len = 1;
	if( Ask( "1000000000000") ){
		for(int i = 10 ; i >= 1 ; -- i){
			string dw;
			for(int j = 1 ; j <= i ; ++ j) dw.push_back( '9' );
			if( Ask( dw ) == false ){
				len = i + 1;
				break;
			}
		}
		string www = "1";
		for(int i = 2 ; i <= len ; ++ i) www.push_back( '0' );
		cout << "! " << www << endl;
		flush( cout );
		return 0;
	}else
		len = PreDeal();
	if( len == 1 ){
		for(int i = 1 ; i <= 9 ; ++ i){
			string w;
			w.push_back( i + '0' );
			w.push_back( '9' );
			if( Ask( w ) ){
				cout << "! " << to_string( i ) << endl;
				flush( cout );
				return 0;
			}
		}
		return 0;
	}
//	cerr << "Len is " << len << endl;
	string Ret = "0";
	for(int i = 0 ; i < len - 1 ; ++ i){
		int l = i ? 0 : 1 , r = 9;
		while( l < r ){
			int mid = l + r + 1 >> 1;
			Ret[i] = mid + '0';
			if( !Ask( Ret ) )
				r = mid - 1;
			else
				l = mid ;
		}
		Ret[i] = l + '0';
		Ret.push_back( '0' );
	}
	Ret.push_back( '0' );
	for(int i = 0 ; i <= 9 ; ++ i){
		Ret[Ret.size() - 2] = i + '0';
		if( Ask( Ret ) == 1 )
			break;
	}
	Ret.pop_back();
	cout << "! " << Ret << endl;
	flush( cout );
	return 0;
}