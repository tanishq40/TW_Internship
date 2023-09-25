#include <iostream>
using namespace std;
char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char currentPlayer = 'X';
void drawBoard() {
    cout << "  0 1 2" << endl;
    for(int i = 0; i < 3; i++) {
        cout << i << " ";
        for(int j = 0; j < 3; j++) {
            cout << board[i][j];
            if(j < 2)
                cout << "|";
        }
        cout << endl;
        if(i < 2)
            cout << "  -----" << endl;
    }
}bool makeMove(int row, int col) {
    if(row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ')
        return false;
         
    board[row][col] = currentPlayer;
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    return true;
}bool checkWin() {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return true;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return true;
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return true;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return true;
    return false;
}bool checkDraw() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ')
                return false;
        }
    }
    return true;
}int main() {
    int row, col;
    bool gameover = false;
    while(!gameover) {
        drawBoard();
        cout << "Player " << currentPlayer << ", enter row (0-2) and column (0-2) separated by a space: ";
        cin >> row >> col;
        if(makeMove(row, col)) {
            if(checkWin()) {
                drawBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameover = true;
            } else if(checkDraw()) {
                drawBoard();
                cout << "It's a draw!" << endl;
                gameover = true;
            }
        } else {
            cout << "Invalid move! Try again." << endl;
        }
    }
    return 0;
}