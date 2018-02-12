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
void swap(ll *A, ll *B){
    ll temp = *A;
    *A = *B;
    *B = temp;
}
 
int main(){
    fast_io;
    if(fopen("tupni.txt", "r")) {
        freopen("tupni.txt", "r", stdin);
        freopen("tuptuo.txt", "w", stdout);
    }
    ll n, k;
    cin>>n>>k;
    ll A[n];
    REP(i,n){
        cin>>A[i];
    }
    
    REP(i,n){
        ll temp=A[i], j=i;
        while(j>0 && A[j]%k<A[j-1]%k){
            swap(A[j], A[j-1]);
            j--;
        }
        A[j]=temp;
    }

    REP(i,n){
        cout<<A[i] << " ";
    }
    return 0;
}