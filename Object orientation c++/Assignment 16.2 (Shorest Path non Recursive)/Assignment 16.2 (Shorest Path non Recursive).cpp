#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


const int rows = 5;
const int cols = 6;
int min_row;
int min_length;
string path[rows][cols];

//calculating the cost of every square and fills in the cost matrix
void calculationCost(){
    static int weight[rows][cols]= {
                                {3,4,1,2,8,6},
                                {6,1,8,2,7,4},
                                {5,9,3,9,9,5},
                                {8,4,1,3,2,6},
                                {3,7,2,8,6,4}};

    static int cost[rows][cols]= {
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0}};};

 // Copy the leftmost column of the weight matrix to the cost matrix, and initialize the leftmost column of the path matrix.
    for(int i =0; i<rows; i++){
        cost[i][0] = weight[i][0];
        path[i][0] = to_string(i);
    }


 // For each remaining column,
      // Calculate the cost of each square in the column (non-recursively),
      // and store the correct number in the cost matrix and the correct string in the path matrix.

    for (int c = 1; c < cols; ++c)                // For each remaining column,
      for (int r = 0; r < rows; ++r) {
         int up = cost[(r+rows-1)%rows][c-1];
         int left = cost[r%rows][c-1];
         int down = cost[(r+1)%rows][c-1];
         int minCost = min(min(up, left), down);

         if (minCost == up)                      // Store the correct numbers in the matrices.
            path[r][c] = path[(r+rows-1)%rows][c-1] + to_string(r);
         else if (minCost == left)
            path[r][c] = path[r][c-1] + to_string(r);
         else
            path[r][c] = path[(r+1)%rows][r-1] + to_string(r);
         cost[r][c] = minCost + weight[r][c];


     min_row = 0, min_length = cost[0][cols-1];      // Check which square in the rightmost column has the lowest cost.
   for (int i = 1; i < rows; ++i)
      if (cost[i][cols-1] < min_length)
         min_row = i, min_length = cost[i][cols-1];

      }
}

int main() {
    calculationCost();
    cout << "The length of the shortest path is " << min_length;
    cout << ".\nThe rows of the path from left to right are " << path[min_row][cols-1] << ".";

   return 0;
}
