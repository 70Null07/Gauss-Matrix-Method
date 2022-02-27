#include <iostream>
#include <locale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    int row = 4, col = 5;

    // Исходная матрица из варианта задания
    double Matrix[5][5] { {5.482, 0.617, 0.520, 0.401, 0.823 }, { 0.607, 4.195, 0.232, 0.570, 0.152 },
                { 0.367, 0.576, 8.193, 0.582, 0.625 }, { 0.389, 0.356, 0.207, 5.772, 0.315 } };

    double Solution[5], sf = 0., rm;
 
    // Вывод введенной матрицы
    cout << "Введенная матрица: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "\t" << Matrix[i][j];
        }
        cout << endl;
    }

    // Прямой ход - привидение матрицы к треугольному виду
    for (int i = 0; i < row - 1; i++)
    {

        for (int j = i + 1; j < row; j++)
        {
            rm = Matrix[j][i];
            for (int k = i; k < col; k++)
            {
                Matrix[j][k] = Matrix[j][k] - (rm * (Matrix[i][k] / Matrix[i][i]));
            }
        }
    }

    // Вывод приведенной к треугольному виду матрицы
    cout << "Приведенная матрица: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout  << round(Matrix[i][j] * 1000) / 1000 << "\t\t";
        }
        cout << endl;
    }

    // Обратный ход - вычисление решений системы
    for (int i = row; i > 0; i--) 
    {
        Solution[i] = (Matrix[i - 1][col - 1] - sf) / Matrix[i - 1][i - 1];
        sf = 0.;
        for (int j = i; j <= row; j++)
        {
            sf = sf + (Matrix[i - 2][j - 1] * Solution[j]);
        }
    }

    // Вывод решений на экран
    cout << "Найденные решения :\n";
    for (int i = 1; i <= row; i++) 
        cout << "u_" << i << " = " << Solution[i] << endl;

    return 0;
}