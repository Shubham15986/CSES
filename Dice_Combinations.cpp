#include<iostream>
#include<algorithm>
  #include <iomanip>



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


// int solve(int sums){
//     if(sums < 0) return 0;
//     if(sums == 0) return 1;
//     if(dp[sums] != -1) return dp[sums];
//     int pick =0;
//     rep(i,1,7){
//          pick = (pick + solve(sums-i))%mod;
//     }
//     return dp[sums] = pick;


// }

void boom(){
     int n;cin>>n;
     vi dp(n+1,0);

     dp[0] =1;
     for(int i=1;i<=n;i++){
        for(int j =1;j<=6;j++){
            if(i-j>=0){
                 dp[i] = (dp[i] + dp[i-j])%mod;
            }
        }
     }
     cout<<dp[n]<<endl;
}

int32_t main() {
    
   int t; //cin>>t;
   t=1;

   while(t--){
    boom();
   }
}