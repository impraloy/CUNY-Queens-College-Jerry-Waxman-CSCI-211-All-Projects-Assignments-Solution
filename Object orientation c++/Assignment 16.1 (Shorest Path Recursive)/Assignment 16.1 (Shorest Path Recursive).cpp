#include <iostream>

using namespace std;

const int rows = 5;
const int cols = 6;
int memo[rows][cols] = {
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0}};

int f(int i, int j) {
    int weight[rows][cols] = { // weight array
        {3, 4, 1, 2, 8, 6},
        {6, 1, 8, 2, 7, 4},
        {5, 9, 3, 9, 9, 5},
        {8, 4, 1, 3, 2, 6},
        {3, 7, 2, 8, 6, 4}};


    // base case
    if(j == 0) {
        memo[i][j] = weight[i][j];
        return weight[i][j];
    }

    // recursive calls
    if(memo[i][j] == 0) {
            int left = weight[i][j] + f(i, j-1);
        int up = weight[i][j] + f((i-1 + rows) % rows, j-1);
        int down = weight[i][j] + f((i+1) % rows, j-1);

        int min;

        if(left < up && left < down) min = left;
        else if(up < down) min = up;
        else min = down;

        memo[i][j] = min; // store calculated value in memo array
        return min; // return lowest cell in previous column

    } else {
        return memo[i][j];

    }
}


int main() {
    int ex[rows]; // store all cells to exit from
    int path[cols] = {-1}; // store route of shortest path
    for(int i = 0; i < rows; i++)
        ex[i] = f(i, cols-1); // populate exit array

    // find lowest cell to exit from
    int min = ex[0];
    path[cols-1] = 0;
    for(int i = 1; i < rows; i++) {
        if(ex[i] < min) {
            min = ex[i];
            path[cols-1] = i; // store the row number in the last cell of route array
        }
    }

    // find rest of the path by working backwards
    for(int c = cols-2; c >= 0; c--) {
        int left = memo[path[c+1]][c];
        int up = memo[(path[c+1] - 1 + rows) % rows][c];
        int down = memo[(path[c+1] + 1) % rows][c];

        if(left < up && left < down) path[c] = path[c+1];
        else if(up < down) path[c] = (path[c+1] - 1 + rows) % rows;
        else path[c] = (path[c+1] + 1) % rows;
    }

    // print
    cout << "The shortest path is of length " << min << endl;

    for(int i = 0; i < cols; i++) {
        cout << path[i] << " ";
    }
    cout << endl;

    return 0;
}




