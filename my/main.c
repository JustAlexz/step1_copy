#include <stdio.h>
int main()
{
    double a, b, c;
    double start, end, step;
    double x, F;
    int wholeA, wholeB, wholeC;
    int bitResult; // Результат побитового выражения
    int i; // Номер шага
    printf("Введите a, b, c через пробел: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
    {
        printf("Ошибка: нужно ввести три числа.\n");
        return 0; // Завершаем программу с ошибкой
    }
    printf("Введите x начальное, x конечное и dx через пробел: ");
    if (scanf("%lf %lf %lf", &start, &end, &step) != 3)
    {
        printf("Ошибка: нужно ввести три числа.\n");
        return 0;
    }
    if (step <= 0 || start > end)
    {
        printf("Ошибка: шаг должен быть положительным,\n");
        printf("а начало интервала не должно превышать конец.\n");
        return 0;
    }
    wholeA = (int)a;
    wholeB = (int)b;
    wholeC = (int)c;
    // Вычисляем выражение Ац И (Вц ИЛИ Сц)
    bitResult = wholeA & (wholeB | wholeC);
    // Выводим заголовок таблицы
    printf("%10s %15s\n", "x", "F");
    // Вычисляем каждое x через номер шага
    for (i = 0; ; i++)
    {
        x = start + i * step;
        // Заканчиваем цикл, когда вышли за конец интервала
        if (x > end)
            break;
        // Первая формула: a*x*x + b*x + c
        if (a < 0 && c != 0)
        {
            F = a * x * x + b * x + c;
        }
        // Вторая формула: -a / (x - c)
        else if (a > 0 && b == 0)
        {
            if (x == c)
            {
                printf("%10.2f %15s\n", x, "не определена");
                continue;
            }
            F = -a / (x - c);
        }
        // Третья формула: a*(x + c)
        else
        {
            F = a * (x + c);
        }
        // Выбираем вещественный или целый результат
        if (bitResult != 0)
        {
            // Выводим четыре знака после запятой
            printf("%10.2f %15.4f\n", x, F);
        }
        else
        {
            // Отбрасываем дробную часть и выводим целое число
            printf("%10.2f %15d\n", x, (int)F);
        }
    }
    return 0;
}
