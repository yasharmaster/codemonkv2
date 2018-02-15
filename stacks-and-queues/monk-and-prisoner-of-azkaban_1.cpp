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
		if(!mystack.empty()) {
			pair<ll,ll> top_element = mystack.top();
			mystack.pop();
			while (top_element.first<A[i]){
				y[top_element.second] = i+1;
				if(mystack.empty()){
					break;
				}
				top_element = mystack.top();
				mystack.pop();
			}
			if (top_element.first>=A[i]){
				mystack.push(top_element);
			}
		}
		mystack.push(make_pair(A[i],i));
	}
	while(!mystack.empty()){
		pair<ll,ll> top_element = mystack.top();
		mystack.pop();
		y[top_element.second] = -1;
	}
	FORD(i,n-1,0){
		if(!mystack.empty()) {
			pair<ll,ll> top_element = mystack.top();
			mystack.pop();
			while (top_element.first<A[i]){
				x[top_element.second] = i+1;
				if(mystack.empty()){
					break;
				}
				top_element = mystack.top();
				mystack.pop();
			}
			if (top_element.first>=A[i]){
				mystack.push(top_element);
			}
		}
		mystack.push(make_pair(A[i],i));
	}
	while(!mystack.empty()){
		pair<ll,ll> top_element = mystack.top();
		mystack.pop();
		x[top_element.second] = -1;
	}
	REP(i,n){
		cout<<x[i]+y[i]<<" ";
	}
	return 0;
}