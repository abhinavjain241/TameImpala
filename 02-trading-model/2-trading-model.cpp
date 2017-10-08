#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define N 100005

int str[N];
vector<int>adj[N];
int dist1[N];
int dist2[N];
int visited1[N];
int visited2[N];

void bfs1(int s){
  visited1[s]=1;
  //dist1[s]=0;
  queue<pair<int,int> >q;
  q.push(mp(s,0));
  while(!q.empty()){
    pair<int,int>top=q.front();
    //cout<<"top="<<top.first<<endl;
    q.pop();
    dist1[top.first]=top.second;
    for(int i=0;i<adj[top.first].size();i++){
      if(!visited1[adj[top.first][i]]){
      q.push(mp(adj[top.first][i],top.second+1));
      visited1[adj[top.first][i]]=1;
      }
    }
  }
}

void bfs2(int s){
  visited2[s]=1;
  //dist1[s]=0;
  queue<pair<int,int> >q;
  q.push(mp(s,0));
  while(!q.empty()){
    pair<int,int>top=q.front();
    q.pop();
    dist2[top.first]=top.second;
    for(int i=0;i<adj[top.first].size();i++){
      if(!visited2[adj[top.first][i]]){
      q.push(mp(adj[top.first][i],top.second+1));
      visited2[adj[top.first][i]]=1;
      }
    }
  }
}

int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>str[i];
  }
  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a;
    cin>>b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  int q;
  cin>>q;
  int cnt1=0;
  int cnt2=0;
  long long int f1=0;
  ll f2=0;
  while(q--){
    int x,y;
    cin>>x;
    cin>>y;
    //cout<<"x="<<x<<endl;
    //cout<<"y="<<y<<endl;
    bfs1(x);
    bfs2(y);
    //cout<<"done"<<endl;
    int val1=0;
    int val2=0;
    for(int i=1;i<=n;i++){
      visited1[i]=0;
      visited2[i]=0;
    }
    for(int i=1;i<=n;i++){
      if(dist1[i]>dist2[i])
        val2+=str[i-1];
      else
        val1+=str[i-1];
    }
    if(val1>=val2)
      cnt1++;
    else
      cnt2++;
    f1+=(ll)(val1);
    f2+=(ll)(val2);
  }
  cout<<cnt1<<" "<<f1<<" "<<cnt2<<" "<<f2;
  return 0;
}