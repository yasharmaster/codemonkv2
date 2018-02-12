#include<iostream>

typedef long long ll;
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)

using namespace std;

typedef long long ll;

void merge(ll *A, ll start, ll mid, ll end, ll x){
    ll n = (end-start+1);
    ll output[n];
    ll k=0,p=start,q=mid+1;

    while(p<=mid && q<=end){
        if(A[p]%x<=A[q]%x){
            output[k++]=A[p++];
        } else {
            output[k++]=A[q++];
        }
    }
    while(p<=mid){
        output[k++]=A[p++];
    }
    while(q<=end){
        output[k++]=A[q++];
    }
    k=0;
    FOR(i,start,end){
        A[i]=output[k++];
    }
}

void mergesort(ll *A, ll start, ll end, ll k){
    if(start<end){
        ll mid = (start+end)>>1;
        mergesort(A, start, mid, k);
        mergesort(A, mid+1, end, k);
        merge(A,start,mid,end,k);
    }
}

int main(){
    ll n, k;
    cin>>n>>k;
    ll A[n];
    REP(i,n){
        cin>>A[i];
    }
    mergesort(A,0,n-1,k);
    REP(i,n){
        cout<<A[i]<<" ";
    }
    return 0;
}