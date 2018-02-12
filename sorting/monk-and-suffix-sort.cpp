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
    if(fopen("tupni.txt", "r")) {
        freopen("tupni.txt", "r", stdin);
        freopen("tuptuo.txt", "w", stdout);
    }
    string A;
    cin>>A;
    ll k;
    cin>>k;
    ll n=A.size();
    string suffixes[n];
    suffixes[n-1]=A[n-1];
    FORD(i,n-2,0){
        suffixes[i]=A[i]+suffixes[i+1];
    }
    sort(suffixes,suffixes+n);
    cout<<suffixes[k-1];
    return 0;
}