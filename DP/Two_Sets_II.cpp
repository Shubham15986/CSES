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

int f(vvi &dp,int in, int tar){
    if(tar == 0) return 1;
    if(in == 0 ) return 0;
    
    
    if(dp[in][tar] != -1) return dp[in][tar];

    int notPick = f(dp,in-1,tar);
    int pick =0;

    if(tar>=in){
        pick = f(dp,in-1,tar-in);
    }
    return  dp[in][tar] =(pick+notPick)%mod;


}


void boom(){
 int n;cin>>n;
 
 int total = n*(n+1)/2;
 vvi dp(n+1,vi(total/2 + 2,-1));
 if(total&1){
     cout<<"0"<<endl;return;
 }
 int modInv = (mod+1)/2;
 cout<<(f(dp,n,total/2)*modInv)%mod;
//cout<<(mod+1)/2<<" "<<modInverse(2,mod)<<endl;

}
int32_t main() {
    
   int t;// cin>>t;
  t=1;

   while(t--){
    boom();
   }
}