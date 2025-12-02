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


void boom(){
   int n, k;
   cin>>n>>k;

   vi dp(k + 1, 1e9);   
   vi v(n);

   rep(i, 0, n) cin>>v[i];
   dp[0] = 0;

   for (auto it : v) {
      for (int i = it; i<=k; i++) {
        dp[i] = min(dp[i], dp[i - it] + 1);  
    }
}

int ans = (dp[k] >= 1e9 ? -1 : dp[k]);
cout<<ans<<endl;
    
}

int32_t main() {
    
   int t; //cin>>t;
   t=1;

   while(t--){
    boom();
   }
}