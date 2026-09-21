#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const int MAX = 20;

    char again;

    do
    {
        int n;
        double a[MAX][MAX + 1];
        double original[MAX][MAX + 1];
        double x[MAX];

        cout << "Enter number of equations: ";
        cin >> n;

        cout << "Enter the augmented matrix:\n";

        // Input matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cin >> a[i][j];
                original[i][j] = a[i][j];
            }
        }

        // Gaussian Elimination
        for (int i = 0; i < n - 1; i++)
        {
            // If pivot is 0, swap with a lower row
            if (fabs(a[i][i]) < 0.000001)
            {
                for (int k = i + 1; k < n; k++)
                {
                    if (fabs(a[k][i]) > 0.000001)
                    {
                        for (int j = 0; j <= n; j++)
                        {
                            swap(a[i][j], a[k][j]);
                        }
                        break;
                    }
                }
            }

            // Make elements below pivot 0
            for (int k = i + 1; k < n; k++)
            {
                if (fabs(a[i][i]) < 0.000001)
                    continue;

                double factor = a[k][i] / a[i][i];

                for (int j = i; j <= n; j++)
                {
                    a[k][j] = a[k][j] - factor * a[i][j];
                }
            }

            // Display matrix
            cout << "\nAfter step " << i + 1 << ":\n";

            for (int r = 0; r < n; r++)
            {
                for (int c = 0; c <= n; c++)
                {
                    cout << a[r][c] << "\t";
                }
                cout << endl;
            }
        }

        // Check for no solution
        bool noSolution = false;

        for (int i = 0; i < n; i++)
        {
            bool zeroRow = true;

            for (int j = 0; j < n; j++)
            {
                if (fabs(a[i][j]) > 0.000001)
                {
                    zeroRow = false;
                    break;
                }
            }

            if (zeroRow && fabs(a[i][n]) > 0.000001)
            {
                noSolution = true;
            }
        }

        if (noSolution)
        {
            cout << "\nThe system has no solution.\n";
        }
        else
        {
            // Find rank
            int rank = 0;

            for (int i = 0; i < n; i++)
            {
                bool nonZeroRow = false;

                for (int j = 0; j < n; j++)
                {
                    if (fabs(a[i][j]) > 0.000001)
                    {
                        nonZeroRow = true;
                        break;
                    }
                }

                if (nonZeroRow)
                    rank++;
            }

            if (rank < n)
            {
                cout << "\nThe system has infinite solution.\n";
            }
            else
            {
                cout << "\nThe system has unique solution.\n";

                // Back substitution
                for (int i = n - 1; i >= 0; i--)
                {
                    x[i] = a[i][n];

                    for (int j = i + 1; j < n; j++)
                    {
                        x[i] = x[i] - a[i][j] * x[j];
                    }

                    x[i] = x[i] / a[i][i];
                }

                // Print solution
                cout << "\nSolution:\n";

                for (int i = 0; i < n; i++)
                {
                    cout << "x" << i + 1 << " = " << x[i] << endl;
                }

                // Verification
                cout << "\nVerification:\n";

                for (int i = 0; i < n; i++)
                {
                    double result = 0;

                    for (int j = 0; j < n; j++)
                    {
                        result = result + original[i][j] * x[j];
                    }

                    cout << "Equation " << i + 1 << ": ";
                    cout << result << " = " << original[i][n];

                    if (fabs(result - original[i][n]) < 0.000001)
                        cout << "  -> Satisfied";
                    else
                        cout << "  -> Not Satisfied";

                    cout << endl;
                }
            }
        }

        cout << "\nSolve another system? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}
