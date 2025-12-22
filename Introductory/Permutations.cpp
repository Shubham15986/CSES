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
int cnt(int k){
    return (k*k)*(k*k-1)/2 - 4*(k-1)*(k-2);
}

void boom(){
   int n;cin>>n;
   if(n==1){
    cout<<"1";
   }else if(n==2 || n==3){
     cout<<"NO SOLUTION";
   }
   else{
      for(int i=2;i<=n;i+=2){
        cout<<i<<" ";
      }
     for(int i=1;i<=n;i+=2){
        cout<<i<<" ";
      }
   }

    
}
int32_t main() { 
   int t; //cin>>t;
   t=1;

   while(t--){
    boom();
   }

}
