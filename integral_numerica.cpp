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

double f(double x) {
    return std::sin(x); // Exemplo de função a ser integrada
}

int main() {
    double a = 0.0; // Limite inferior
    double b = M_PI; // Limite superior
    int n; // Número de subintervalos

    std::cout << "Digite o número de subintervalos (n): ";
    std::cin >> n;

    double resultado = aproximação_trapezios(f, a, b, n);

    // integral extata de sin(x) de 0 a pi é 2

    double v_exato = 2.0;

    //calculo do erro exato 

    double erro_exato = std::abs(v_exato - resultado);

    double erro_estimado = (std::pow((b - a), 3) / (12 * std::pow(n, 2))) * 1; // |f''(x)| <= 1 para sin(x)
    
    std::cout << "Aproximação da integral usando " << n << " intervalos: " << resultado << std::endl;
    std::cout << "Valor exato da integral: " << v_exato << std::endl;
    std::cout << "Erro exato usando " << n << " intervalos: " << erro_exato << std::endl;
    std::cout << "Erro estimado usando " << n << " intervalos: " << erro_estimado << std::endl;    
    std::cout << "Diferença entre erro exato e estimado: " << std::abs(erro_exato - erro_estimado) << std::endl; 

    return 0;
}

// Exemplo de uso: integrar sin(x) de 0 a pi

