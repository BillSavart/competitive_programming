/* @JUDGE_ID: BillSavart 10189 C++ "Minesweeper" */

/* @BEGIN_OF_SOURCE_CODE */
#include<iostream>

using namespace std;

int main(void){
    int height, width;
    while(cin >> height >> width){
        char map[height][width];
        int output_map[height][width];

        for(int i; i < height; i++)
            for(int j; j < width; j++)
                cin >> map[i][j];
            
        for(int i; i < height; i++)
            for(int j; j < width; j++)
                cout << map[i][j] << " ";
        cout << endl;
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */