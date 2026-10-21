
#include <iostream>
using namespace std;

int main()
{
    int seats[10][4] = {0};
    int total, row, seat;
    int booked = 0;
    int fullRows = 0;

    cout << "AIRLINE SEAT RESERVATION SYSTEM" << endl;

    cout << "How many seats do you want to reserve? ";
    cin >> total;

    while (total < 0 || total > 40)
    {
        cout << "Enter a number between 0 and 40: ";
        cin >> total;
    }

    // Reserve seats
    while (booked < total)
    {
        cout << "\nEnter row number (1-10): ";
        cin >> row;

        cout << "Enter seat number (1-4): ";
        cin >> seat;

        if (row < 1 || row > 10 ||
            seat < 1 || seat > 4)
        {
            cout << "Invalid row or seat number!" << endl;
        }
        else if (seats[row - 1][seat - 1] == 1)
        {
            cout << "Seat already booked" << endl;
        }
        else
        {
            seats[row - 1][seat - 1] = 1;
            booked++;
            cout << "Seat reserved successfully!" << endl;
        }
    }

    // Display seating arrangement
    cout << "\nSEATING ARRANGEMENT" << endl;
    cout << "Row\tSeats" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << "\t";

        for (int j = 0; j < 4; j++)
        {
            cout << seats[i][j] << " ";
        }

        cout << endl;
    }

    // Identify fully booked rows
    for (int i = 0; i < 10; i++)
    {
        int count = 0;

        for (int j = 0; j < 4; j++)
        {
            if (seats[i][j] == 1)
            {
                count++;
            }
        }

        if (count == 4)
        {
            fullRows++;
        }
    }

    cout << "\nTotal fully booked rows: "
         << fullRows << endl;

    return 0;
}
