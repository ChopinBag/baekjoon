#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

enum class Direction {
    RIGHT = 0,
    LEFT,
    UP,
    DOWN
};

class Snake{
    public:
        Snake(int r, int c, Direction d){
            this->row = r;
            this->col = c;
            this->dir = d;
        }
        void go_next(Direction d){
            
        }

    private:
        int row;
        int col;
        Direction dir;
};


int main(){
    int board_size, apple_num;
    cout << "Enter the size of board" << endl;
    cin >> board_size;
    cout << "Enter the number of apples" << endl;
    cin >> apple_num;
    
    vector<vector<int>> board[board_size][board_size];

    map<int, int> apple_location;
    for(int i=0;i<apple_num;++i){
        int row, col;
        cin >> row >> col;
        apple_location[row] = col;
    }
}