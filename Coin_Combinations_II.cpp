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


              
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define sz(x) (int)(x).size()
#define int long long

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define repd(i, a, b) for (int i = (a); i >= (b); i--)
#define each(x, a) for (auto &x : a)
const int mod = 1e9 + 7;

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


 
 
// int solve(vi &v,int n, int sums){
//     if(n== 0 || sums <0) return 0;
//     if(sums == 0) return 1;
//     if(dp[n][sums] != -1) return dp[n][sums];
//     int not_pick = solve(v,n-1, sums);
//     int pick =0;
//     if(sums >= v[n-1]){
//         pick = solve(v,n,sums-v[n-1]);
//     }
//     return dp[n][sums] = pick+ not_pick;


// }



void boom(){

   int n,k;
   cin>>n>>k;
  // vvi dp(n+1, vi(k+1, 0)); 
   vi v(n);
   for(int i=0;i<n;i++) cin>>v[i];

   vi prev(k+1,0);
   prev[0] = 1;

   for(int i=1;i<=n;i++){
      vi curr(k+1,0);
      curr[0] =1;
      for(int j=1;j<=k;j++){
        int not_pick = prev[j];
        int pick =0;
        if(j - v[i-1] >= 0) pick  = curr[j-v[i-1]];
        curr[j] = (pick + not_pick)%mod;

    }
    prev = curr;
}
cout<<prev[k]<<endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
   int t; //cin>>t;
   t=1;

   while(t--){
    boom();
   }
}