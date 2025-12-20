#include<iostream>
#include<algorithm>
  #include <iomanip>
  #include<queue>



#include<unordered_map>
#include<map>
#include<set>
#include<vector>
#include <numeric>
#include<cstring>
#include<climits>

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
const int mod = 1e9 + 7;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define vii vector<pii>
#define in(v,n) rep(i,0,n) cin>>v[i];
#define out(v,n) rep(i,0,n) cout<<v[i]<<" "; cout<<endl;
#define pairout(v,n) rep(i,0,n) cout<<v[i].first<<" "<<cout<<v[i].second<<" "; cout<<endl;
int modexp(int a, int b, int mod){
    int res = 1;
    while(b){
        if(b & 1)
            res = (int)((1LL * res * a) % mod);
        a = (int)((1LL * a * a) % mod);
        b >>= 1;
    }
    return res;
}

int modInverse(int a, int mod){
    return modexp(a, mod - 2, mod);
}
const int INF = -1e9;
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int f(vvi &dp, vi &v,int lef,int rig){
    if(lef>rig) return 0;
    if(lef==rig) return v[lef];
    if(dp[lef][rig] != -10)  return dp[lef][rig];

    int left = min(f(dp,v,lef+2,rig),f(dp,v,lef+1,rig-1)) +v[lef];
    int right = min(f(dp,v,lef+1,rig-1),f(dp,v,lef,rig-2))+v[rig];

    return dp[lef][rig] =max(left,right);


}


void boom(){
 int n;cin>>n;
 vi v(n);
 rep(i,0,n) cin>>v[i];
 vvi dp(n+1,vi(n+1,-10));

 cout<<f(dp,v,0,n-1)<<endl;
 



}
int32_t main() {
    
   int t;// cin>>t;
  t=1;

   while(t--){
    boom();
   }
}