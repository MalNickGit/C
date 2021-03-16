#include <stdio.h>
#include <math.h>

int main(void) {

	int iteration = 0; //Переменная для подсчёта проходов
	double e = 0.0000001; //Константа для вычисления (пока слагаемое больше, работает цикл do-while)
	double sum = 0; //Начальное значение суммы

	while (iteration++ < 1000000) {
		double term = 0; //Начальное значение слагаемого
		sum = 0; //Обнуление суммы
		
		double fn[2] = {2,3}; //Установка начальных значений fib (по условию)
		double nextFib = 0; //Здесь записывается следующее значение ряда Фибоначчи

		double factorial = 1; //Начальное значение факториала

		double powVar = 4; //Начальное значение четвёрки
		double i = 2; //Начальное значение переменной для вычисления факториала
		double sqrtDif = 3; //Начальное значение для вычисления корня из числа
		do {
			//fib
			nextFib = fn[0] + fn[1];
			fn[0] = fn[1];
			fn[1] = nextFib;
			//fib

			factorial = factorial * i; //Факториал
			i++; //Увеличение i при каждой итерации для подсчёта факториала

			term = (nextFib * powVar * sqrt(sqrtDif)) / factorial; //Подсчёт текущего слагаемого и всей суммы
			sqrtDif++; //+1 (по условию)
			
			powVar = powVar * 4 * 4; //Степени четвёрки
			
			sum += term; //Сумма ряда
		} while (term > e);
	}
	printf("%f\n", sum);
}
