//metodo de simpson para aproximar funções 
#include <iostream>
#include <cmath>

double aproximação_trapezios(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double soma = 0.5 * (f(a) + f(b));
    
    for (int i = 1; i < n; ++i) {
        soma += f(a + i * h);
    }
    
    return soma * h;
}

double aproximacao_simpson(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double soma = f(a) + f(b);

    for (int i = 1; i < n; i += 2) {
        soma += 4 * f(a + i * h);
    }
    for (int i = 2; i < n - 1; i += 2) {
        soma += 2 * f(a + i * h);
    }

    return soma * h / 3.0;
}

double f(double x) {
    return std::exp(x); // Exemplo de função a ser integrada
}

int main() {
    double a = 0.0; // Limite inferior
    double b = 1.0; // Limite superior
    int n; // Número de subintervalos

    std::cout << "Digite o número de subintervalos pares (n): ";
    std::cin >> n;

    if (n % 2 != 0) {
        std::cerr << "n deve ser par para o método de Simpson." << std::endl;
        return 1;
    }

    double resultado_simpson = aproximacao_simpson(f, a, b, n);
    double resultado_trapezios = aproximação_trapezios(f, a, b, n);

    // integral exata de e^x de 0 a 1 é e - 1
    double v_exato = std::exp(1) - 1;

    //calculo do erro exato 
    double erro_exato_simpson = std::abs(v_exato - resultado_simpson);

    std::cout << "Aproximação da integral usando Simpson para " << n << " intervalos: " << resultado_simpson << std::endl;
    std::cout << "Aproximação da integral usando Trapézios para " << n << " intervalos: " << resultado_trapezios << std::endl;
    std::cout << "Valor exato da integral: " << v_exato << std::endl;
    std::cout << "Erro exato de Simpson " << n << " intervalos: " << erro_exato_simpson << std::endl;
    std::cout << "Erro exato de Trapézios " << n << " intervalos: " << std::abs(v_exato - resultado_trapezios) << std::endl;
    std::cout << "Diferença entre os dois métodos: " << std::abs(resultado_simpson - resultado_trapezios) << std::endl;

    return 0;
}
