#include <iostream>
#include <vector>
#include <list>
#include <numeric>
#include <cmath>
using namespace std;


double mean(const vector<double>& numbers) {
    //calculo da média aritmetica
    if(numbers.empty()){
        return 0.0;
    }
    double sum = 0.0;
    sum = accumulate(numbers.begin(), numbers.end(), 0);
    return sum/(int) numbers.size(); // média dos elementos de numbers
}

std::pair<double,double> interval(const std::vector<double>& numbers){
    pair<double,double> result;
    result.first = *max_element(numbers.begin(), numbers.end());
    result.second = *min_element(numbers.begin(), numbers.end());
    return result;
}

double variance(const std::vector<double>& numbers) {
    double media = mean(numbers); //pega a média dos numeros
    double variance = 0;
    for (int i = 0; i < numbers.size(); i++) {
        variance = variance + pow((numbers[i] - media), 2);
    }
    return (double)variance/numbers.size();
}

double std_dev(const std::vector<double>& numbers) {
    return std::sqrt(variance(numbers));
}

int main() {
//    double myNumbers[] = {10.0,20.0,10.0,20.0,20.0, -5, 99};
    double myNumbers[] = {4, 5, 2, 7, 6};
    vector<double> myVector(myNumbers, myNumbers + sizeof(myNumbers) / sizeof(double));

    auto inter = interval(myVector);
    auto varian = variance(myVector);
    auto std_d = std_dev(myVector);

    cout<<"Maximo: "<<inter.first << "\n"<< "Minimo: "<< inter.second <<endl;
    cout<<"Variancia: "<<varian<<endl;
    cout<<"Desvio padrao: "<<std_d<<endl;

    return 0;
}