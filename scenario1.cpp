// Question: 1
// Sales Report Analysis
// Language: C++

#include <iostream>
#include <vector>
#include <iomanip> // Needed for setting decimal precision for the average
using namespace std;

int main()
{
  // --- Get User Input ---
  int numDays;
  cout << "Enter the number of days: ";
  cin >> numDays;

  if (numDays <= 0)
  {
    cout << "Invalid input. Number of days must be at least 1." << endl;
    return 1; // Exit with an error
  }

  vector<int> sales(numDays);
  cout << "Enter the sales for each day, separated by spaces: " << endl;
  for (int i = 0; i < numDays; ++i)
  {
    cin >> sales[i];
  }

  int maxSale = sales[0];
  int minSale = sales[0];
  int maxDay = 1;
  int minDay = 1;
  double totalSales = 0.0;

  // --- Process the Data in a Single Loop ---
  for (int i = 0; i < numDays; i++)
  {
    totalSales += sales[i];
    if (sales[i] > maxSale)
    {
      maxSale = sales[i];
      maxDay = i + 1;
    }
    if (sales[i] < minSale)
    {
      minSale = sales[i];
      minDay = i + 1;
    }
  }

  // --- Calculate and Display the Final Report ---
  double averageSales = totalSales / numDays;

  cout << "\n--- Sales Report ---" << std::endl;
  cout << "Maximum Sale: " << maxSale << " on Day " << maxDay << endl;
  cout << "Minimum Sale: " << minSale << " on Day " << minDay << endl;
  cout << "Average Sale: " << fixed << setprecision(2) << averageSales << endl;

  return 0;
}

// --- Explanation of Approach ---
// My approach uses a single loop to iterate through the daily sales array efficiently.
// I initialize max and min sales with the first day's value. Inside the loop,
// I update these values if a new max or min is found and also keep a running sum of total sales.
// After the loop, I calculate the average and print all the results.