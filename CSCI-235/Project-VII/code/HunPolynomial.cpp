// Robi Gurung
// Professor Pavel Shostak
// Project IV
// 09 May 2022
#include "HunPolynomial.hpp"

HunPolynomial::HunPolynomial()
{
    //ctor
}

HunPolynomial::HunPolynomial(std::initializer_list<int> num_list){
    for(auto i = num_list.begin(); i != num_list.end(); i++) {
        this->coefficient.push_back(*i);
    }
}

HunPolynomial::HunPolynomial(std::vector<int> coeffiecient){
    for(int i=0; i<coeffiecient.size(); i++){
        this->coefficient.push_back(coeffiecient.at(i));
    }
}

void HunPolynomial::Set(std::vector<int> new_coef){
    this->coefficient.clear();
    for(int i=0; i<new_coef.size(); i++){
        this->coefficient.push_back(new_coef.at(i));
    }
}

float HunPolynomial::operator()(float x){
    return this->coefficient.at(x);
}

HunPolynomial HunPolynomial::operator+(HunPolynomial b){
    std::vector<int> values;
    int big_counter, small_counter;
    int choose = 1;
    if(this->coefficient.size()>b.getCoefficient().size()){
        small_counter = b.getCoefficient().size();
        big_counter = this->coefficient.size();
        // Choose 0 means selection First Polynomial
        choose = 0;
    }else{
        small_counter = this->coefficient.size();
        big_counter = b.getCoefficient().size();
    }
    int skip = big_counter - small_counter;
    for(int i=0; i<big_counter; i++){
        if(i<skip){
            if(choose == 0){
                values.push_back(this->coefficient.at(i));
            }else{
                values.push_back(b.getCoefficient().at(i));
            }
        }else{
             if(choose == 0){
                values.push_back(this->coefficient.at(i)+b.getCoefficient().at(i-skip));
            }else{
                values.push_back(this->getCoefficient().at(i-skip)+b.getCoefficient().at(i));
            }
        }
    }
    HunPolynomial result(values);
    return result;
}

HunPolynomial HunPolynomial::operator-(HunPolynomial b){
    std::vector<int> values;
    int big_counter, small_counter;
    int choose = 1;
    if(this->coefficient.size()>b.getCoefficient().size()){
        small_counter = b.getCoefficient().size();
        big_counter = this->coefficient.size();
        // Choose 0 means selection First Polynomial
        choose = 0;
    }else{
        small_counter = this->coefficient.size();
        big_counter = b.getCoefficient().size();
    }
    int skip = big_counter - small_counter;
    for(int i=0; i<big_counter; i++){
        if(i<skip){
            if(choose == 0){
                values.push_back(this->coefficient.at(i));
            }else{
                values.push_back(b.getCoefficient().at(i)*-1);
            }
        }else{
             if(choose == 0){
                values.push_back(this->coefficient.at(i)-b.getCoefficient().at(i-skip));
            }else{
                values.push_back(this->getCoefficient().at(i-skip)-b.getCoefficient().at(i));
            }
        }
    }
    HunPolynomial result;
    result.Set(values);
    return result;
}

HunPolynomial HunPolynomial::operator*(HunPolynomial b){
    std::vector<int> values;
    int big_counter, small_counter;
    int choose = 1;
    if(this->coefficient.size()>b.getCoefficient().size()){
        small_counter = b.getCoefficient().size();
        big_counter = this->coefficient.size();
        // Choose 0 means selection First Polynomial
        choose = 0;
    }else{
        small_counter = this->coefficient.size();
        big_counter = b.getCoefficient().size();
    }
    int skip = big_counter - small_counter;
    int arr_size = big_counter + small_counter - 1;
    int arr[arr_size];
    /*                   0  1  2  3  4  5
        HunPolynomial A{ 2, 0, 0, 0, 1, 6 };
        HunPolynomial B{ 1, -4, 0 };
        2 -8  0
           0  0  0
              0  0  0
                 0  0   0
                    1  -4   0
                        6 -24 0
        ------------------------
        2@7-8@6+0+0+1@3+2@2-24@1
    */
    for(int i=0; i<arr_size; i++){
       arr[i] = 0;
    }
    for(int i=0; i<big_counter; i++){
        if(choose==0){
            for(int j=0; j<small_counter; j++){
                arr[i+j] += this->coefficient.at(i)*b.getCoefficient().at(j);
            }
        }else{
            for(int j=0; j<small_counter; j++){
                arr[i+j] += this->coefficient.at(j)*b.getCoefficient().at(i);
            }
        }
    }
    for(int i=0; i<arr_size; i++){
       values.push_back(arr[i]);
    }
    HunPolynomial result;
    result.Set(values);
    return result;
}

std::vector<int> HunPolynomial::getCoefficient(){
    return this->coefficient;
}

HunPolynomial::~HunPolynomial()
{
    //dtor
}

std::ostream& operator<<(std::ostream& out, HunPolynomial& h){
    std::stringstream ss;
    std::string series = "";
    std::string temp = "";
    int power_count = h.getCoefficient().size() - 1;
    int total = h.getCoefficient().size();
    int current_number = 0;
    for(int i=0; i<total-2; i++){
        current_number = h.getCoefficient().at(i);
        if(current_number != 0){
            if(i == 0){
                if(current_number<0){
                    series += "- ";
                }
                if(abs(current_number) != 1){
                    ss << abs(current_number) << "*x^" << power_count;
                }else{
                    ss << "x^" << power_count;
                }
                ss >> temp;
                series += temp + " ";
            }else{
                if(abs(current_number) != 1){
                    if(current_number < 0){
                        series += "- ";
                        ss << abs(current_number) << "*x^" << power_count;
                    }else{
                        series += "+ ";
                        ss << abs(current_number) << "*x^" << power_count;
                    }
                    ss >> temp;
                    series += temp + " ";
                }else{
                    if(current_number < 0){
                        series += "- ";
                        ss << "x^" << power_count;
                    }else{
                        series += "+ ";
                        ss << "x^" << power_count;
                    }
                    ss >> temp;
                    series += temp + " ";
                }
            }
        }
    power_count--;
    ss.str("");
    ss.clear();
    }
    for(int i=total-2; i<total; i++){
        current_number = h.getCoefficient().at(i);
        if(current_number != 0){
            if(i==total-2){
                if(abs(current_number) != 1){
                    if(current_number < 0){
                        series += "- ";
                        ss << abs(current_number) << "*x";
                    }else{
                        series += "+ ";
                        ss << abs(current_number) << "*x";
                    }
                    ss >> temp;
                    series += temp + " ";
                }else{
                    if(current_number < 0){
                        series += "- ";
                        ss << "x";
                    }else{
                        series += "+ ";
                        ss << "x";
                    }
                    ss >> temp;
                    series += temp + " ";
                }
            }else{
                if(abs(current_number) != 1){
                    if(current_number < 0){
                        series += "- ";
                        ss << abs(current_number);
                    }else{
                        series += "+ ";
                        ss << abs(current_number);
                    }
                    ss >> temp;
                    series += temp + " ";
                }else{
                    if(current_number < 0){
                        series += "- 1";
                    }else{
                        series += "+ 1";
                    }
                }
            }
            ss.str("");
            ss.clear();
        }
    }
    out<<series;
    return out;
};

int abs(int x){
    if(x<0){
        return x*-1;
    }
    return x;
}
