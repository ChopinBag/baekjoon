#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

enum class Direction {
    RIGHT = 0,
    DOWN,
    LEFT,
    UP
};

class Snake{
    public:
        Snake() = default;
        Snake(vector<vector<int>> &b,Direction d = Direction::RIGHT){
            this->body = b;
            this->dir = d;
        };
        void go_next(Direction d){
            
        }
        void setup(vector<vector<int>> &b, int size){
            b.assign(size, vector<int>(size, 0));
            b[0][0] = 1; // 뱀 머리의 첫번째 위치
        }

    private:
        vector<vector<int>> body;
        Direction dir;
        
};


int main(){
    int board_size, apple_num;
    cout << "Enter the size of board" << endl;
    cin >> board_size;
    cout << "Enter the number of apples" << endl;
    cin >> apple_num;
    
    vector<vector<int>> board;
    board.assign(board_size, vector<int>(board_size, 0));
    vector<vector<int>> body;

    Snake s;
    s.setup(body, board_size);

    for(int i=0;i<apple_num;++i){
        int row, col;
        cin >> row >> col;
        board[row][col] = 1;
    }
}