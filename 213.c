#define eps 14 // точность вычисления косинуса
#define pog 0.000001 // погрешность
#define pi 3.14159265358979 // значение числа пи
double cos1(double x) { // функция,вычисляющая косинус
  double c=1,n=0,a=1;
  for (int i=1; i<=eps; i++)
  {
      a*=(-1.0*x*x)/((2*n+1)*(2*n+2)); // ряд Тейлора для косинуса
      c+=a; // сумма всех слагаемых в формуле (само значение косинуса)
      n++; // счётчик для вычисления факториала
  }
  return c; // возвращает значение косинуса
}
int test_cos1() {
  int R=1,n=6,k=0;
  double b[6]={0.0, 1.0, 5.0, pi/3.0, pi, pi/6.0}; // значения, подставляемые в косинус
  double a[6]={1.0, 0.54030230586814, 0.28366218546323, 0.5, -1.0, 0.86602540378444}; // значения,которые должны получиться
  for (int i = 0; i < n; i++) {
    R=R && (cos1(b[k])>=a[k]-pog && cos1(b[k])<=a[k]+pog); // проверка равенства значений с учётом погрешности
    k++;
    if (R==0) break; // выход из цикла если хотя бы 1 из проверок неудачная
  }
  return R; // возвращает 1 если всё совпало, 0 - если нет
}
int main() {
  return !test_cos1(); // программа завершится с кодом 0, если R=1, и наоборот
}
