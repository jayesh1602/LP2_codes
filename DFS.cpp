/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void DFS(int src,vector<int>adj[],vector<int>&vis){
    vis[src] = 1;
    cout<<src<<" ";
    for(auto it:adj[src]){
        if(!vis[it]){
            DFS(it,adj,vis);
        }
    }
}

void BFS(vector<int>adj[],queue<int>&q,vector<int>&vis){
    if(q.empty()){
        return;
    }
    
    int node = q.front();
    q.pop();
    cout<<node<<" ";
    for(auto it:adj[node]){
        if(!vis[it]){
            vis[it] = 1;
            q.push(it);
        }
    }
    BFS(adj,q,vis);
}

int main()
{
    int n;
    cout<<"enter nodes ";
    cin>>n;
    int m;
    cout<<"enter edges ";
    cin>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int>vis(n,0);
    // cout<<"DFS : ";
    // DFS(0,adj,vis);
    
    cout<<"BFS : ";
    queue<int>q;
    q.push(0);
    vis[0] = 1;
    BFS(adj,q,vis);

    return 0;
}

