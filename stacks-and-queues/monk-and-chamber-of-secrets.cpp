#include <iostream>
#include <cstdio>
#include <climits>
#include <stack>
#include <queue>
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
	ll n,x,value;
	cin>>n>>x;
	queue<pair<ll,ll> > A,B;
	REP(i,n){
		cin>>value;
		if(DBG){
			wi(value) LOG(" pushed")
		}
		A.push(make_pair(value, i+1));
	}
	REP(X,x){
		ll max_val = INT_MIN;
		REP(i,x){
			if(!A.empty()){
				pair<ll,ll> p = A.front();
				max_val = max(max_val, p.first);
				if(DBG){
					wi(p.first) LOG(" popped")
				}
				A.pop();
				B.push(p);
			}
		}
		bool printed = false;
		while(!B.empty()){
			pair<ll,ll> p = B.front();
			B.pop();
			if(!printed && p.first == max_val){
				cout<<p.second<<" ";
				printed = true;
				if(DBG){
					wi(p.first) LOG(" selected")
				}
				continue;
			}
			if(p.first){
				p.first--;
			}
			if(DBG){
				wi(p.first) LOG(" pushed")
			}
			A.push(p);
		}
	}
	return 0;
}