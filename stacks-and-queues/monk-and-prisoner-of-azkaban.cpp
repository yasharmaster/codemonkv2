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
	ll n;
	cin>>n;
	ll A[n];
	REP(i,n) {
		cin>>A[i];
	}
	vector<ll> x(n,-1),y(n,-1);
	stack<pair<ll,ll> > mystack;

	REP(i,n){
		if(DBG){
			LOG(A[i])
		}
		if(!mystack.empty()) {
			pair<ll,ll> mystack_top = mystack.top();
			ll potential_big_value = mystack_top.first, potential_big_index = mystack_top.second;
			while(potential_big_index!=-1 && potential_big_value <= A[i]){
				if(DBG){
					wi(potential_big_value)
				}
				potential_big_index = x[potential_big_index];
				potential_big_value = A[potential_big_index];
			}
			x[i] = potential_big_index;
			if(DBG){
				wi(x[i])
			}
		}
		mystack.push(make_pair(A[i],i));
	}

	while(!mystack.empty()){
		mystack.pop();
	}

	if(DBG){
		LOG("finding y");
	}

	FORD(i,n-1,0){
		if(DBG){
			LOG(A[i])
		}
		if(!mystack.empty()) {

			pair<ll,ll> mystack_top = mystack.top();
			ll potential_big_value = mystack_top.first, potential_big_index = mystack_top.second;
			while(potential_big_index!=-1 && potential_big_value <= A[i]){
				if(DBG){
					wi(potential_big_value)
				}
				potential_big_index = y[potential_big_index];
				potential_big_value = A[potential_big_index];
			}
			y[i] = potential_big_index;
			if(DBG){
				wi(y[i])
			}
		}
		mystack.push(make_pair(A[i],i));
	}

	REP(i,n){
		if(x[i]!= -1){
			x[i]++;
		}
		if(y[i]!= -1){
			y[i]++;
		}
		cout<<x[i]+y[i]<<" ";
	}
	return 0;
}