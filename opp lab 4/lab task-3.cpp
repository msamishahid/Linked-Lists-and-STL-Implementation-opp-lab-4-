#include <list>
#include <iostream>
using namespace std;
void printMatrix(const list<list<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }
}
void addRow(list<list<int>>& matrix, const list<int>& newRow) {
    matrix.push_back(newRow);
}
void deleteRow(list<list<int>>& matrix, int rowIndex) {
    if (rowIndex < 0 || rowIndex >= matrix.size()) {
        cout << "Invalid row index." << endl;
        return;
    }
    auto it = matrix.begin();
    advance(it, rowIndex);
    matrix.erase(it);
}
int main() {
    list<list<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << "Initial Spreadsheet:" << endl;
    printMatrix(matrix);
    list<int> newRow = { 10, 11, 12 };            // Add a new row
    addRow(matrix, newRow);
    cout << "\nAfter Adding a New Row:" << endl;
    printMatrix(matrix);
    int rowIndexToDelete = 1;                // Deleting the second row
    deleteRow(matrix, rowIndexToDelete);
    cout << "\nAfter Deleting Row " << rowIndexToDelete + 1 << ":" << endl;
    printMatrix(matrix);
    return 0;
}
