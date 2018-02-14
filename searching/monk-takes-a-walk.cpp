#include <iostream>
#include <cstdio>
#include <climits>
#include <stack>
#include <vector>
#include <string>

#define LOG(x) cerr << "*** " << x << " ***" << endl;
#define wi(x) what_is(x, '\n')
#define wisp(x) what_is(x, ", ")
#define what_is(x, terminator) cerr << #x << " = " << x << terminator;

typedef long long ll;

#define DBG false
#define endl "\n"
#define DEBUG(x) cout << '>' << #x << ':' << x << '\n';
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back
#define fast_io     ios_base::sync_with_stdio(0);cin.tie(NULL)

using namespace std;

typedef vector<ll> vi;
typedef vector<vector<ll> > vvi;

int main(){
	fast_io;
	if(fopen("tupni.txt", "r")) {
		freopen("tupni.txt", "r", stdin);
		freopen("tuptuo.txt", "w", stdout);
	}
	ll t;
	cin >> t;
	while (t--) {
	    string str;
	    cin>>str;
	    ll count = 0;
	    REP(i, str.size()){
	    	switch(str[i]){
	    		case 'a':
	    		case 'e':
	    		case 'i':
	    		case 'o':
	    		case 'u':
	    		case 'A':
	    		case 'E':
	    		case 'I':
	    		case 'O':
	    		case 'U':
	    			count++;
	    			break;
	    	}
	    }
	    cout<<count<<endl;
	}
	return 0;
}