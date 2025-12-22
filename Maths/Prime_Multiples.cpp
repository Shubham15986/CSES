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



#define repd(i, a, b) for (int i = (a); i >= (b); i--)
#define each(x, a) for (auto &x : a)
const int mod = 1e9 + 7;
#define int long long

#define vvi vector<vector<int>>
#define pii pair<int,int>
#define vii vector<pii>
#define in(v,n) rep(i,0,n) cin>>v[i];
#define out(v,n) rep(i,0,n) cout<<v[i]<<" "; cout<<endl;
#define pairout(v,n) rep(i,0,n) cout<<v[i].first<<" "<<cout<<v[i].second<<" "; cout<<endl;
const int INF = -1e9;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define vi vector<int>
int powe(int a,int b,int mod){
    int mul = 1;
    while(b>0){
        if(b&1) mul = (((mul)%mod) * (a%mod))%mod;
        a = ((a%mod) * (a%mod))%mod;
        b/=2;
    }
    return mul%mod;
}
int sums(int a,int b){
     a%=mod;b%=mod;
     int l = (b-a + 1 +mod)%mod;
     int r = (a+ b)%mod;
     int newmod = (mod+1)/2;
     int t = (l*r%mod)*newmod%mod;
     return t;
}

void boom(){
    int n;cin>>n;
    int k;cin>>k;
    vi v(k);
    rep(i,0,k)cin>>v[i];
    int ans =0;

    rep(i,1,(1LL<<k)){
        int bitcnt=0;
        __int128 pr=1;
        rep(j,0,k){
            if(i&(1LL<<j)){
                pr*=v[j];bitcnt++;
                if(pr>n) break;
            }
          
        }
        if(pr>n) continue;
        int cnt = n/pr;
        if(bitcnt&1){
          ans+=cnt;
        }else{
          ans-=cnt;
        }
    }
    cout<<ans<<endl;
}
int32_t main() { 
   int t; //cin>>t;
   t=1;

   while(t--){
    boom();
   }

}
