#include<iostream>
#include<algorithm>
  #include <iomanip>

#include<unordered_map>
#include<map>
#include<set>
#include<vector>
#include <numeric>

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



void boom(){
    int n;
cin >> n;
vvi dif(2002, vector<int>(2002, 0));

vector<tuple<int,int,int,int>> v;

rep(i, 0, n) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    //a--;b--;c--;d--;
    v.push_back({a, b, c, d});
   // a--,b--,c--,d--;
    b++;d++;
    dif[a][c]++;
    dif[a][d]--;
    dif[b][c]--;
    dif[b][d]++;
}


rep(i, 0, 2002) {
    rep(j, 1, 2002) {
        dif[i][j] = dif[i][j] + dif[i][j-1];
    }
}
rep(i, 1, 2002) {
    rep(j, 0, 2002) {
        dif[i][j] = dif[i][j] + dif[i-1][j];
    }
}
vvi preOne(2002,vi(2002,0));
int cnt_total = 0;
rep(i, 0, 2002) {
    rep(j, 1, 2002) {
        if(dif[i][j ] >= 1) cnt_total++;
        if(dif[i][j ] == 1) dif[i][j] = 1;
        else dif[i][j] = 0;
    }
}
rep(i, 0, 2002) {
    rep(j, 1, 2002) {
        preOne[i][j] = preOne[i][j-1] + dif[i][j];
    }
}
rep(i,0,2002){
    rep(j,1,2002){
        preOne[j][i] = preOne[j-1][i] + preOne[j][i];
    }
}

  for( auto [p,q,r,s]: v){
     //   p--;q--;r--;s--;
       int cnt =0;
       cnt  = preOne[q][s] - preOne[p-1][s] - (preOne[q][r-1] - preOne[p-1][r-1]);
      cout<< 4000000 + cnt - cnt_total <<endl;
  }
    // rep(i,0,10){
    //    rep(j,0,10){
    //       cout<<dif[i][j]<<" ";
    //    }
    //    cout<<"\n";
    // }

}


int32_t main() {
    
   int t;

  t=1;

   while(t--){
    boom();
   }
}