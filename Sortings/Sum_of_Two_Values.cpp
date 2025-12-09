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
const int INF = 1e9;
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
  
void boom(){
    int n,x;cin>>n>>x;
    vi v(n);
    map<int,int> mpp;
    rep(i,0,n){
        int a;cin>>a;
        v[i] = a;
        mpp[a] = i+1;
    }
    if( n==1){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    bool flag = false;
    vii ans;
    rep(i,0,n){
        int tar = x-v[i];
        // int u = mpp[v[i]];
        // mpp[v[i]]--;
        // if(mpp[v[i]]<=0)mpp.erase(v[i]);
        if(mpp.count(tar) && mpp[tar]>i+1){
            ans.pb({i+1,mpp[tar]});
            flag = true;
            break;
        }
        // mpp[v[i]] = u;
    }
    if(!flag){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    cout<<ans[0].first<<" "<<ans[0].second<<endl;
   
}
int32_t main() {
    
   int t; //cin>>t;
   t=1;

   while(t--){
    boom();
   }
}