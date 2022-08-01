#include <iostream>

using namespace std;

const int size = 3;
string grid[size][size];

//Initializes the 2D array
void startGrid()
{
    for (int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            grid[i][j] = "*";
        }
    }

}

//Will display the current grid
void drawGrid()
{
    printf("    |    |    \n");
    printf("  %s |  %s | %s \n", grid[0][0].data(), grid[0][1].data(), grid[0][2].data());
    printf("    |    |    \n");
    printf("--------------\n");
    printf("    |    |    \n");
    printf("  %s |  %s | %s \n", grid[1][0].data(), grid[1][1].data(), grid[1][2].data());
    printf("    |    |    \n");
    printf("--------------\n");
    printf("    |    |    \n");
    printf("  %s |  %s | %s \n", grid[2][0].data(), grid[2][1].data(), grid[2][2].data());
    printf("    |    |    \n");

    cout << endl;
}

//Validation to see for a winner
bool checkHor()
{
    for (int i = 0; i < size; i++){
        if ((grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) && grid[i][0] != "*")
        {
            return true;
        }
    }

    return false;
}
bool checkVert()
{
    for (int i = 0; i < size; i++){
        if ((grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) && grid[0][i] != "*")
        {
            return true;
        }
    }

    return false;
}
bool checkDiag()
{
    if ((grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) && grid[0][0] != "*" ){
        return true;
    }

    if ((grid[2][2] == grid[1][1] && grid[1][1] == grid[0][2]) && grid[2][2] != "*" ){
        return true;
    }

    return false;
}

//Checks if spot is empty or if position is out of bounds
bool validSpot(int pos){
    if ((pos > 0 && pos < 4) && grid[0][pos - 1] == "*"){
        return true;
    }
    if ((pos > 3 && pos < 7) && grid[1][pos - 4] == "*"){
        return true;
    }
    if ((pos > 6 && pos < 10) && grid[2][pos - 7] == "*"){
        return true;
    }
    cout << "false" << endl;
    return false;
}
//Adds the spot to the 2D array
void spotSelect(int pos, string turn)
{
   if (pos > 0 && pos < 4)
    {
        grid[0][pos - 1] = turn;
    }else if (pos > 3 && pos < 7){
        grid[1][pos - 4] = turn;
    }else if (pos > 6 && pos < 10){
        grid[2][pos - 7] = turn;
    }
}

int main()
{
    int counter = 1;
    string turn;
    int pos;
    int turnCounter = 0;

    startGrid();
    //!checkDiag() || !checkHor() || !checkVert()
    while(true)
    {
        if (checkHor() || checkVert() || checkDiag()){
            drawGrid();
            counter --;
            if(counter % 2 == 0){
                turn = "X";
            }else{
                turn = "O";
            }

            cout << "The winner is ";
            cout << turn;
            cout << "!!";
            break;
        }

        if (counter != 10){
            if(counter % 2 == 0){
                turn = "X";
            }else{
                turn = "O";
            }

            drawGrid();

            cout << "Please select a position from 1-9" << endl;
            cin >> pos;

            if (validSpot(pos)){
                counter ++;
                spotSelect(pos, turn);
            }
        }else{
            drawGrid();
            cout << "The game is a draw.";
            break;
        }
    }

}
