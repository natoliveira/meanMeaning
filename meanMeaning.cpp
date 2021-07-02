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

double mode(const vector<double>& numbers) {
    //calculo da mode_calc
    int count = 0;
    int count2 = 0;
    double mode_calc = -1;

    for (int i = 0; i < numbers.size(); i++) { //cada numero
        for (int j = i + 1; j < numbers.size(); j++) { //compara com todos os outros do vetor
            if (numbers[i] == numbers[j]) {
                count++;
                if (count > count2) {
                    count2 = count;
                    mode_calc = numbers[i];
                }
            }
        }
        count = 0;
    }
    return mode_calc;
}

double percentile(const vector<double>& numbers, int parts) {
    if(numbers.empty()){
        return 0.0;
    }
    int i = floor((double)parts * (double)numbers.size()/100.0);
    return numbers[i];
}

double median(const std::vector<double>& data) {
    return percentile(data, 50);
}
//double mode_focker(const vector<double>& numbers){
//    struct num_times{
//        double number;
//        int times;
//    };
//
//    vector<num_times> dict_numbers
//
//}

int main() {
    double myNumbers[] = {10.0,20.0,10.0,20.0,20.0}; // vetor de double
    vector<double> myVector(myNumbers, myNumbers + sizeof(myNumbers) / sizeof(double));
    auto me = mean(myVector); // calcula a média
    auto mo = mode(myVector);
    auto pe = percentile(myVector, 25);
    auto med = median(myVector);

    cout<<"Media: "<<me<<endl;
    cout<<"Moda: "<<mo<<endl;
    cout<<"Percentil: "<<pe<<endl;
    cout<<"Mediana: "<<med<<endl;

    return 0;
}

