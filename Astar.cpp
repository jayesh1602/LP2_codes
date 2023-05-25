/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

using Gamestate = vector<vector<int>>;
using Cord = pair<int,int>;

int manHatan(Cord p1,Cord p2){
    return abs(p1.first-p2.first)+abs(p1.second-p2.second);
}



vector<Gamestate> Solve(Gamestate start,Gamestate goal){
    vector<Cord> movement = {{-1,0},{1,0},{0,-1},{0,1}};
    
    priority_queue<pair<int,Gamestate>,vector<pair<int,Gamestate>>,greater<pair<int,Gamestate>>>openlist;
    
    // Gamestate,gscore
    map<Gamestate,int>gscore;
    
    //curr,pred
    map<Gamestate,Gamestate>predesor;
    
    gscore[start] = 0;
    
    openlist.push({manHatan({0,0},{2,2}),start});
    
    while(!openlist.empty()){
        
        Gamestate current = openlist.top().second;
        openlist.pop();
        
        
        if(current == goal){
            vector<Gamestate>path;
            while(current != start){
                path.push_back(current);
                current = predesor[current];
                
            }
            path.push_back(start);
            reverse(path.begin(),path.end());
            return path;
        }
        
        Cord emptyCell;
        for(int i=0;i<current.size();i++){
            for(int j=0;j<current[i].size();j++){
                if(current[i][j] == 0){
                    emptyCell = {i,j};
                    break;
                }
            }
        }
        
        for(auto it:movement){
            int newRow = emptyCell.first + it.first;
            int newCol = emptyCell.second + it.second;
            
            if(newRow >=0 && newRow < 3 && newCol>=0 && newCol <3){
                Gamestate neighbour = current;
                swap(neighbour[newRow][newCol],neighbour[emptyCell.first][emptyCell.second]);
                
                int gScoreval = gscore[current]+1;
                
                if(gscore.find(neighbour) == gscore.end() || gScoreval < gscore[neighbour]){
                    gscore[neighbour] = gScoreval;
                    predesor[neighbour] = current;
                    int fScore = gScoreval+manHatan({newRow,newCol},{2,2});
                    openlist.push({fScore,neighbour});
                }
            }
        }
    }
    
    return {};
    
}

int main()
{
    Gamestate start = {{8, 7, 6}, {5, 4, 3}, {2, 1, 0}};
    Gamestate goal = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    
    
    //  Gamestate start = {{1,2,3},{4,0,5},{6,7,8}};
    // Gamestate goal = {{1, 2, 3}, {4, 5, 6}, {7, 8,0}};
    
    vector<Gamestate>path = Solve(start,goal);
    if(path.size() == 0){
        cout<<"no path found..";
    }
    else{
       for(auto it:path){
           for(auto it2:it){
               for(int i:it2){
                   cout<<i<<" ";
               }
               cout<<endl;
           }
           cout<<endl;
       }
       
    }
    
    
    
    
    return 0;
}


