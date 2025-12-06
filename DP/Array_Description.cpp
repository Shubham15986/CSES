#include<iostream>
#include<algorithm>
  #include <iomanip>
  #include<climits>



#include<unordered_map>
#include<map>
#include<set>
#include<vector>
#include <numeric>
#include<cstring>

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
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// int solve(int n, int k, vector<int>& v) {
//     if (k == 0) return 0;
//     if (n == 0) return 1e9;

//     if (dp[n][k] != -1) return dp[n][k];

//     int not_pick = solve(n-1, k, v);

//     int pick = 1e9;
//     if (k - v[n-1] >= 0) {
//         pick = 1 + solve(n, k - v[n-1], v);
//     }

//     return dp[n][k] = min(pick, not_pick);
// }

bool check(int m,int n){
    return m>=1 && m<=n;
}

void boom(){
   int n,m;cin>>n>>m;
   vi v(n);
   rep(i,0,n) cin>>v[i];

   vvi dp(n+1,vi(m+1,0));

   rep(i,1,m+1){
     if(v[0] == i|| v[0] == 0){
        dp[1][i] = 1;
     }
   }
   rep(i,2,n+1){
    rep(k,1,m+1){
        if(v[i-1]!=0 && v[i-1] !=k){
            dp[i][k] = 0;
            continue;
        }
        for(int r = k-1;r<=k+1;r++){
            if(!check(r,m)) continue;
            dp[i][k]= (dp[i][k] + dp[i-1][r])%mod;
        }
    }
   }
   int sums =0;
   rep(i,1,m+1){
      sums = (sums+dp[n][i])%mod;
   }
   cout<<sums<<endl;
    
}

int32_t main() {
    
   int t; //cin>>t;
   t=1;

   while(t--){
    boom();
   }
}