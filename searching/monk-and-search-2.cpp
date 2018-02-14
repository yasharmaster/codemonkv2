#include <iostream>
#include <cstdio>
#include <climits>
#include <stack>
#include <algorithm>
#include <string>

#define LOG(x) cerr << "*** " << x << " ***" << endl;
#define wi(x) what_is(x, '\n')
#define wisp(x) what_is(x, ", ")
#define what_is(x, terminator) cerr << #x << " = " << x << terminator;

typedef long long ll;

#define DBG true
#define endl "\n"
#define DEBUG(x) cout << '>' << #x << ':' << x << '\n';
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back
#define fast_io     ios_base::sync_with_stdio(0);cin.tie(NULL)

using namespace std;

int main(){
	fast_io;
	if(fopen("tupni.txt", "r")) {
		freopen("tupni.txt", "r", stdin);
		freopen("tuptuo.txt", "w", stdout);
	}
	ll n;
	cin>>n;
	ll A[n];
	REP(i,n){
		cin>>A[i];
	}
	sort(A,A+n);
	ll queries, type, q;
	cin>>queries;
	while(queries--){
		cin>>type>>q;
		if(!type){
			cout<<(n-(ll)(lower_bound(A,A+n,q)-A))<<endl;
		}
		else {
			cout<<(n-(ll)(upper_bound(A,A+n,q)-A))<<endl;
		}
	}
	return 0;
}