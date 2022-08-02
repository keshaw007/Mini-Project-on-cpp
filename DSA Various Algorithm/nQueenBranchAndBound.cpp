#include<bits/stdc++.h>
using namespace std;
void branchAndBound(vector<vector<bool>> board, int row, vector<bool> cols, vector<bool> ndiag, vector<bool> rdiag, string asf){
    if(row==board.size()){
        cout<<asf<<"."<<"\n";
        return;
    }
    for(int col=0; col<board.size(); col++){
        if(!cols[col] and !ndiag[row+col] and !rdiag[row-col+board.size()-1]){
            board[row][col]=true;
            cols[col]=true;
            ndiag[row+col]=true;
            rdiag[row-col+board.size()-1]=true;
            branchAndBound(board, row+1, cols, ndiag, rdiag, asf+to_string(row)+"-"+to_string(col)+", ");
            board[row][col]=false;
            cols[col]=false;
            ndiag[row+col]=false;
            rdiag[row-col+board.size()-1]=false;
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<bool>> board(n, vector<bool>(n));
    vector<bool> cols(n);
    vector<bool> ndiag(2*n-1);
    vector<bool> rdiag(2*n-1);
    branchAndBound(board, 0, cols, ndiag, rdiag, "");
}