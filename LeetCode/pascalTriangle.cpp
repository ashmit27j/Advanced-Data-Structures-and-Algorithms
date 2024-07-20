#include <iostream>
#include <vector>

using namespace std;

// Function to generate Pascal's Triangle
vector<vector<int>> generatePascalTriangle(int numRows) {
    vector<vector<int>> triangle;

    for (int i = 0; i < numRows; ++i) {
        vector<int> row(i + 1, 1); // Initialize row with 1s

        for (int j = 1; j < i; ++j) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }

        triangle.push_back(row);
    }

    return triangle;
}

// Function to print Pascal's Triangle
void printPascalTriangle(const vector<vector<int>>& triangle) {
    for (const auto& row : triangle) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int numRows;

    cout << "Enter the number of rows for Pascal's Triangle: ";
    cin >> numRows;

    vector<vector<int>> triangle = generatePascalTriangle(numRows);

    cout << "Pascal's Triangle:" << endl;
    printPascalTriangle(triangle);

    return 0;
}
