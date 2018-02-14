#include <iostream>
#include <cstdio>
#include <cmath>
#include <stack>
#include <algorithm>
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

int main(){
	fast_io;
	if(fopen("tupni.txt", "r")) {
		freopen("tupni.txt", "r", stdin);
		freopen("tuptuo.txt", "w", stdout);
	}
	ll n, q, x;
	cin>>n>>q;
	ll L[n+1],R[n+1],D[n+1];
	L[0] = R[0] = D[0] = 0;
	FOR(i,1,n){
		cin>>L[i]>>R[i];
	}
	FOR(i,1,n){
		D[i] = D[i-1]+R[i]-L[i]+1;
	}
	while(q--){
		cin>>x;
		ll index = (ll)(lower_bound(D,D+n,x)-D);
		cout<<L[index] + x - D[index-1] - 1<<endl;
	}
	return 0;
}