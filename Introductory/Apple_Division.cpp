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
const int INF = 1e18;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define vi vector<int>

int minDif;
int total;
void f(int n, vi &v, int tar){
    if(n<0){
        minDif =min(minDif, llabs(total-2*tar));
        return;
    }
    f(n-1,v,tar);
    f(n-1,v, tar+v[n]);
    return;

}
void boom(){
    int n;cin>>n;
    vi v(n);
    rep(i,0,n)cin>>v[i];
    minDif = 1e18;
    total = accumulate(all(v),0LL);
    f(n-1,v,0);
    cout<<minDif<<endl;

}
int32_t main() { 
   int t; //cin>>t;
   t=1;

   while(t--){
    boom();
   }

}

