/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;




// ----------------------------------  N queen --------------------
// A utility function to print solution
void printSolution(vector<vector<int>>&board,int N)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(board[i][j])
				cout<<("Q ");
			else
				cout<<(". ");
		}
		cout<<("\n");
	}
}


bool isSafe(vector<vector<int>>&board, int row, int col,int n)
{

	for (int i = 0; i < col; i++)
		if (board[row][i])
			return false;
    
    int i=row,j=col;
    while(i>=0 && j>=0){
        if(board[i][j]){
            return false;
        }
        i--;
        j--;
    }
    i = row,j=col;
    while(i<n && j>=0){
        if(board[i][j]){
            return false;
        }
        i++;
        j--;
    }
    return true;

}

bool solveNQUtil(vector<vector<int>>&board, int col,int N)
{

	if (col >= N)
		return true;
		
	for (int i = 0; i < N; i++) {
		
		if (isSafe(board, i, col,N)) {
			board[i][col] = 1;
			if (solveNQUtil(board, col + 1,N))
				return true;
				
			board[i][col] = 0; // BACKTRACK
		}
	}

	return false;
}

//-------------------------------------------


int main()
{
        int n;
        cout<<"enter n ";
        cin>>n;
        vector<vector<int>>board(n,vector<int>(n,0));
    
    	if (solveNQUtil(board, 0,n) == false) {
    		cout<<("Solution does not exist");
    	}
    	else{
    	    printSolution(board,n);
    	}



    //-------------------------
	return 0;
	
}