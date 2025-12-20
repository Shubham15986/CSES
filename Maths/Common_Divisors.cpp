#include "bits/stdc++.h"
 
using namespace std;
 
 
 
#define int long long               
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define sz(x) (int)(x).size()
 
 
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define repd(i, a, b) for (int i = (a); i >= (b); i--)
#define each(x, a) for (auto &x : a)
//onst int mod = 1e9 + 7;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define vii vector<pii>
#define in(v,n) rep(i,0,n) cin>>v[i];
#define out(v,n) rep(i,0,n) cout<<v[i]<<" "; cout<<endl;
#define pairout(v,n) rep(i,0,n) cout<<v[i].first<<" "<<cout<<v[i].second<<" "; cout<<endl;
//const int INF = 1e9;
const int mod = 1e9+7;
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int powe(int a,int b,int mod){
    int mul = 1;
    while(b>0){
        if(b&1) mul = (((mul)%mod) * (a%mod))%mod;
        a = ((a%mod) * (a%mod))%mod;
        b/=2;
    }
    return mul%mod;
}
 
void boom(){
    vi v(1000002,0);
  
   rep(i,1,1000002){
     for(int j=i;j<=1000001;j+=i){
        v[j]++;
     }
   }
   int n;cin>>n;
   while(n--){
     int x;cin>>x;cout<<v[x]<<endl;
   }
   
 
 
}
int32_t main() {
    
   int t; //cin>>t;
  t=1;
 
   while(t--){
    boom();
   }
}