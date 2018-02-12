#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <climits>

#define LOG(x) cerr << "*** " << x << " ***" << endl;

typedef long long ll;

#define DBG false
#define endl "\n"
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define fast_io     ios_base::sync_with_stdio(0);cin.tie(NULL)

#define DIG 100000

using namespace std;

void counting_sort(ll *A, ll n, ll mul){
    vector<ll> freq(DIG,0);
    REP(i,n){
        freq[(A[i]/mul)%DIG]++;
    }
    FOR(i,1,DIG-1){
        freq[i]+=freq[i-1];
    }
    ll output[n];
    FORD(i,n-1,0){
        ll index = (A[i]/mul)%DIG;
        output[freq[index]-1] = A[i];
        freq[index]--;
    }
    REP(i,n){
        A[i]=output[i];
    }
}

void radix_sort(ll *A, ll n){
    ll max = INT_MIN;
    REP(i,n){
        if(max<A[i]){
            max = A[i];
        }
    }
    for(ll exp=1; max/exp>0; exp*=100000){
        counting_sort(A,n,exp);
        REP(i,n){
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }
}

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
    radix_sort(A, n);
    return 0;
}