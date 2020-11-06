#include <iostream>
#include <cmath>
#include <fstream>

double factorial(double n)
{
  if(n==0)
  {
    return 1;
  }
  else
  {
    n = n*factorial(n-1);
  }
  return n;
}

double bessel(double x, double n)
{
  double sum = 0;
  for(double i = 0; i<=14; ++i)
  {
    sum += (std::pow(-1, i)*std::pow(x, 2*i+n))/(std::pow(2, 2*i+n)*factorial(i)*factorial(i+n));
  }
  return sum;
}

double infield(double x, double n)
{
  double sum = 0;
  for(double i = 0; i<=14; ++i)
  {
    sum += (std::pow(x, 2*i+n))/(std::pow(2, 2*i+n)*factorial(i)*factorial(i+n));
  }
  return sum;
}

int main() {
 double x_min = 0.0, x_max = 10, h =0.1;
  int N = (x_max - x_min)/h;
  std::ofstream fout("datos.txt");
  for(int i=0; i<=N; ++i)
  {
    double xi = x_min + i*h;
    fout  << xi << "\t"
          << bessel(xi, 0) << "\t"
          << bessel(xi, 1) << "\t"
          << bessel(xi, 2) << "\t"
          << bessel(xi, 3) << "\t"
          << bessel(xi, 4) << "\n";
  }
  fout.close();
}